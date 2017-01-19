/*
  Copyright (c) Mario Garcia, Under the GNU Public v2 License.
 */
#include <symbol/hash.h>


unsigned int
reverse_byte(char *byte)
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
unsigned int
toy_hash(void *value, unsigned int size)
{
  // Still workin on it.
  unsigned int hash, count = 0;
  while (count < size)
  {
    char val = *(char *)(value+count);
    hash = reverse_byte(&val);
  }
  
  return hash;
}
