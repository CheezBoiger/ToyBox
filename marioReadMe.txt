y.tab.c

he used a sed command in make to add the printf line
Not sure how to do this with cmake I need to go to class
Didn't fix much except the parser doesn't throw syntax erros any more
If we can get the reduce statments correct it should be good enough
  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  printf("[Shifting on %d] \n",yytoken);
