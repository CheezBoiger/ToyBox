/*
  Copyright (c) Mario Garcia, Michael Wallace, Under the GNU Public v3 License.
 */
#ifndef __TOYBOX_PARSER_H
#define __TOYBOX_PARSER_H


#include <err/types.h>
#include <parser/stack.h>


struct parser_t;


/*
  Generic parser function. 
 */
typedef int32 (*parser_func)(struct parser_t *, char *, uint32);



/*

 */
struct parser_t {
  /**
     Algorithm used by the parse engine.
   */
  parser_func algorithm;
  /**
     stack used.
   */
  struct stack_t stack;
  int32 left_size;
  int32 right_size;
  /**
     left array.
   */
  char *left;
  /**
     right array
   */
  char *right;
};


int32 toy_parser_init(parser_func algorithm);


/**
   Toybox Parser.
 */
int32 toy_parse(char *, uint32 size);



int32 toy_parser_cleanup();

#endif // __TOYBOX_PARSER_H
