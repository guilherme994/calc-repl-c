#ifndef PARSER_H
#define PARSER_H

void parser(char* text, char* num_1, char* num_2, char* ope);
int parser_num(const char* num, int* result);
void parser_operator(char* op_temp, char* op);

#endif
