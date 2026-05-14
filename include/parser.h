#ifndef PARSER_H
#define PARSER_H

int parser(char* text, int* n_1, int* n_2, char* ope);
int parser_num(const char* num, int* result);
void parser_operator(char* op_temp, char* op);

#endif
