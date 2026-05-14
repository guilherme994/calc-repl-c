#include <stdlib.h>
#include <string.h>
#include "../include/parser.h"

int parser(char* text, int* n_1, int* n_2, char* ope) {
  char* token = strtok(text, " ");
  char num_1[20], num_2[20], op[20];
  int contador = 0;
  while(token != NULL) {
    if(contador == 0) strcpy(num_1, token);
    else if(contador == 1) strcpy(op, token);
    else if(contador == 2) strcpy(num_2, token);

    token = strtok(NULL, " ");
    contador ++;
  }

  parser_operator(op, ope);
  parser_num(num_1, n_1);
  parser_num(num_2, n_2);

  return 0;
};


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
}
