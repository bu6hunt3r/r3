var r2pipe=require("r2pipe");
var r2=null;

function analFunction(funcName) {
        r2p.cmdj("pdfj @"+funcName.name, function(err,res){
		//console.log(res);
        });
}

r2pipe.lpipe(function a(err,r2) {
r2p=r2;
console.log("Analyzing file")
r2.cmdj('aaa', function (res) {
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
