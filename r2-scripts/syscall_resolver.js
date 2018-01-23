var r2pipe=require("r2pipe");
var r2=null;
var pendingSyscalls = 0;

function syscallName(num) {
	for (var x = 0; x < syscalls.length; x++) {
		if (syscalls[x].num == num)
			return syscalls[x].name;
	}
}

function commentSyscall(num, offset) {
	var scNum = parseInt(num, 16);
	var scName = syscallName(scNum);
	console.log(' - found Syscall: ' + scName+' '+offset.toString(16).toUpperCase());

	/*Set comment*/
	var cmd='CC LINUX - sys_'+scName+' @'+offset;
	pendingSyscalls++;
	
	console.log(cmd);
	r2p.cmd(cmd, function (res) {
		pendingSyscalls--;
		if(!pendingSyscalls)
			r2p.quit();
	});

}

function analFunction(funcName) {
	//console.log(funcName.name);
	r2p.cmdj("pdfj @"+funcName.name, function(err,res){
	if(err) {
		throw err;
	}

		for (var x = res.ops.length - 1; x >= 0; x--) {
			//console.log(res.ops[x].bytes);
			if (res.ops[x].bytes === 'cd80') {
				//console.log("Found interrupt");
				/* Seach for syscall number */
				for (var i = x - 1; i >= 0; i--) {

					/* Exit if we find another syscall */
					if (res.ops[i].bytes === 'cd80')
						break;
					
					/* Ignore non mov opcodes */
					if (res.ops[i].type !== 'mov')
							continue;

					if (res.ops[i].opcode.match(/ eax,| ax,| al,/) !== null) {
						var num = res.ops[i].opcode.split(',')[1].trim();
						//console.log("Found syscall num", num)
						/* Reject non valid hex */
						if (num.match(/^[x0-9a-f]+$/) === null)
							continue;

						commentSyscall(num, res.ops[x].offset);
					}
				}
			}
		}
	});
}

r2pipe.lpipe(function a(err,r2) {
r2p=r2;
console.log("Analyzing file")
r2.cmdj('aac', function (res) {
        console.log('Analysis finished');
        // Get syscalls
        r2.cmdj('asj', function(err,sc) {
            if(err) {
                throw err;
            }
            syscalls=sc;
            //console.log(sc);
            console.log('Searching for syscalls');
            // List functions
            r2.cmdj('aflj', function (err,res) {
		if(err) {
			throw err;
		}
                //res=JSON.parse(res.res);
                /* console.log(res); */
                res.forEach(analFunction);
            });
        });
    });
});
