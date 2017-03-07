/*
 */

#include <parser/stack.h>
#include <stdlib.h>


int32 stack_init(struct stack_t *s)
{
  if (!s) return 0;

  s->stack_arr = calloc(1, sizeof(char) * 100);
  s->total_size = sizeof(char) * 100;

  s->top = -1;

  return 1;
}


int32 stack_pop(struct stack_t *s, char *output)
{
  if (!s) return 0;
  if (s->top <= -1) return 0;
  if (!output) return 0;
  
  *output = s->stack_arr[s->top];

  s->top = s->top - (sizeof(char));
  return 1;
}


int32 stack_push(struct stack_t *s, char input)
{
  if (!s) return 0;


  s->top = s->top + 1;
  if (s->top >= s->total_size)
  {
    char *temp_arr = malloc(s->total_size * 2);
    for (size_t i = 0; i < s->total_size; ++i)
    {
      temp_arr[i] = s->stack_arr[i];
    }

    free(s->stack_arr);
    s->stack_arr = temp_arr;
    s->total_size = s->total_size * 2;
  }
  
  s->stack_arr[s->top] = input;
  return 1;
}


int32 stack_cleanup(struct stack_t *s)
{
  if (!s) return 1;

  if (s->stack_arr)
  {
    free(s->stack_arr);
    s->stack_arr = NULL;
  }

  s->total_size = 0;
  s->top = -1;
  return 1;
}
