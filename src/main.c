#include <debugger/debug.h>
#include <token/scanner.h>


int main(int c, char *args[])
{
  printf("%s\n", get_lang_table_pair((enum ToyboxLang)1000)->str);
  return 0;
}
