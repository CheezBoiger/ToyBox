/*
  Copyright (c) Mario Garcia, Michael Wallace, Under the GNU Public v2 License.
 */
#ifndef __TOYBOX_TYPES_H
#define __TOYBOX_TYPES_H



#include <errno.h>


enum err_t {
  err_success = 1,
  err_fail = 0,
  err_warn = -1
};


typedef int int32;
typedef unsigned int uint32;

typedef short int16;
typedef unsigned short uint16;

typedef long int64;
typedef long long uint64;

typedef char int8;
typedef unsigned char uint8;

typedef float real32;
typedef double real64;





#endif // __TOYBOX_TYPES_H
