
#include <cstdio>
#include <cstdlib>
#include <utility>

#include "ToyKg.h"

int main(int argc, char **argv)
{
    static const u8 OutputA[32] = 
    {
        0x30, 0x68, 0x6F, 0x77, 0x34, 0x7A, 0x64, 0x79, 
        0x38, 0x31, 0x6A, 0x70, 0x65, 0x35, 0x78, 0x66, 
        0x75, 0x39, 0x32, 0x6B, 0x61, 0x72, 0x36, 0x63, 
        0x67, 0x69, 0x71, 0x33, 0x6C, 0x73, 0x74, 0x37
    };
    
    union
    {
        u8  byte[32];
        u32 word[8];
    } HwId;
    
    printf("Give me your hardware id: ");
    if( 8 != scanf("%08X%08X-%08X%08X-%08X%08X-%08X%08X", 
        &HwId.word[0], &HwId.word[1], &HwId.word[2], &HwId.word[3], 
        &HwId.word[4], &HwId.word[5], &HwId.word[6], &HwId.word[7])
        )
    {
        printf("Malformed hardware id.\n");
        return -1;
    }
    
    u32 DiskId = FindVolumeInfo(HwId.byte);
    std::pair<u32, u32> Serial = GenerateSerial(HwId.byte, OutputA);
    
    printf("This hardware id came from disk %08X"
           " and can be unlocked by %08X-%08X\n", 
           DiskId, Serial.second, Serial.first^Serial.second);
    
    return 0;
}
