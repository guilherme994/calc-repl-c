#include <stdlib.h>
#include <string.h>
#include "../include/parser.h"

int parser_num(const char* num, int* result)  {
  char* p_end;
  *result = strtol(num, &p_end, 10);
  if(num == p_end) return 1;
  else return 0;
}

char parser_operator(const char* operator)  {
  if(!strcmp(operator, "+")) return '+';
  else if(!strcmp(operator, "-")) return '-';
  else if(!strcmp(operator, "/")) return '/';
  else if(!strcmp(operator, "x")) return 'x';
  else return 'E';
}
