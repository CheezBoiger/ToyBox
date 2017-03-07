/*

 */
#include <parser/parser.h>
#include <stdlib.h>
#include <debugger/debug.h>


struct parser_t parse_engine;



int32 toy_parser_init(parser_func algorithm)
{
  parse_engine.algorithm = NULL;
  
  if (!algorithm) return 0;
 
  parse_engine.algorithm = algorithm;

  parse_engine.left = calloc(1, sizeof(char) * 50);
  parse_engine.right = calloc(1, sizeof(char) * 50);

  parse_engine.left_size = sizeof(char) * 50;
  parse_engine.right_size = sizeof(char) * 50;

  stack_init(&parse_engine.stack);
  return 1;
}


int32 toy_parse(char *w, uint32 size)
{
  if (!parse_engine.algorithm)
    return -1;

  return parse_engine.algorithm(&parse_engine, w, size);
}


int32 toy_parser_cleanup()
{
  if (parse_engine.left)
  {
    free(parse_engine.left);
    parse_engine.left = NULL;
    parse_engine.left_size = NULL;
  }

  if (parse_engine.right)
  {
    free(parse_engine.right);
    parse_engine.right = NULL;
    parse_engine.right_size = 0;
  }

  stack_cleanup(&parse_engine.stack);
}
