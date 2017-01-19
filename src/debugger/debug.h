/*
  Copyright (c) Mario Garcia, Under the GPL v2 License.
*/
#ifndef __TOYBOX_DEBUGGER_H
#define __TOYBOX_DEBUGGER_H

#include <stdio.h>
#include <assert.h>

#if defined(_DEBUG) || defined(TOYBOX_DEBUG)
 #define debug(stmt, ...) printf(stmt, ##__VA_ARGS__)
 #define toy_assert(cond, msg) assert(cond && msg)
#else
 #define debug(stmt, ...)
 #define toy_assert(cond, msg)
#endif

#endif // __TOYBOX_DEBUGGER_H
