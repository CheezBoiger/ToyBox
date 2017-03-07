/*
 */

#ifndef __TOYBOX_LR_H
#define __TOYBOX_LR_H



#include <parser/parser.h>



int32 slr_parse_algorithm(struct parser_t *parser, char *w, uint32 word_size);


#endif // __TOYBOX_LR_H
