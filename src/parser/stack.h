/*
  Copyright (c) Mario Garcia, Michael Wallace, Under the GNU Public v3 License.
 */
#ifndef __TOYBOX_STACK_H
#define __TOYBOX_STACK_H


#include <err/types.h>



struct stack_t {
  int32 top;
  int32 total_size;
  char *stack_arr;
};




int32 stack_init(struct stack_t *s);


int32 stack_pop(struct stack_t *s, char *output);


int32 stack_push(struct stack_t *s, char input);


int32 stack_cleanup(struct stack_t *s);

#endif // __TOYBOX_STACK_H
