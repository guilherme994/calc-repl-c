#include <stdlib.h>
#include <string.h>
#include "../include/parser.h"

void parser(char* text, char* num_1, char* num_2, char* ope) {
  char* token = strtok(text, " \t\n");
  int contador = 0;

  while(token != NULL) {
    if(contador == 0) strcpy(num_1, token);
    else if(contador == 1) strcpy(ope, token);
    else if(contador == 2) strcpy(num_2, token);
    token = strtok(NULL, " ");
    contador ++;
  }
}

int parser_num(const char* num, int* result)  {
  char* p_end;
  *result = strtol(num, &p_end, 10);
  if(num == p_end) return 1;
  else return 0;
}

void parser_operator(char* op_temp, char* op)  {
  if(!strcmp(op_temp, "+")) *op = '+';
  else if(!strcmp(op_temp, "-")) *op = '-';
  else if(!strcmp(op_temp, "/")) *op = '/';
  else if(!strcmp(op_temp, "x")) *op = 'x';
  else *op = '?';
}
