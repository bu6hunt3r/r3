
#ifndef __TOYKG_H__
#define __TOYKG_H__

#include <utility>
#include <cstdint>

typedef uint8_t   u8;
typedef uint32_t u32;
typedef uint64_t u64;

u32 FindVolumeInfo(const u8 HwId[32]);
std::pair<u32,u32> GenerateSerial(const u8 A[32], const u8 B[32]);

#endif

