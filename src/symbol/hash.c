/*
  Copyright (c) Mario Garcia, Under the GNU Public v2 License.
 */
#include <symbol/hash.h>

// Includeing xxhash for the noncryptographic hash.
#define XXH_PRIVATE_API
#include <symbol/xxhash.h>


uint32 reverse_byte(char *byte)
{
  unsigned int hash = 0;
  hash |= (*byte & 0x80) >> 7;
  hash |= (*byte & 0x40) >> 5;
  hash |= (*byte & 0x20) >> 3;
  hash |= (*byte & 0x10) >> 1;
  hash |= (*byte & 0x8) << 1;
  hash |= (*byte & 0x4) << 3;
  hash |= (*byte & 0x2) << 5;
  hash |= (*byte & 0x1) << 7;
  return hash;
}


/*
  Quick and simple hash.
 */
uint64
toy_hash(void *value, unsigned int size)
{
  // Still workin on it.
  uint64 hash = 0;
  hash = XXH64(value, size, 11); 
  return hash;
}
