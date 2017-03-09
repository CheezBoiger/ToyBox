/*
 */
#include <parser/slr.h>
#include <lex/lexical.h>

extern int yyparse();


int32 slr_parse_algorithm(struct parser_t *parser, char *w, uint32 word_size)
{
  yyparse();
  return 1;
}
