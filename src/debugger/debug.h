/*
  Copyright (c) Mario Garcia, Under the GPL v2 License.
*/
#ifndef __TOYBOX_DEBUGGER_H
#define __TOYBOX_DEBUGGER_H

#include <stdio.h>

#if defined(_DEBUG) || defined(TOYBOX_DEBUG)
 #define debug(stmt, ...) printf(stmt, ##__VA_ARGS__)
#else
 #define debug(stmt, ...)
#endif

#endif // __TOYBOX_DEBUGGER_H
