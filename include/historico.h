#ifndef HISTORICO_H
#define HISTORICO_H

#define HISTORICO_MAX 100

typedef struct {
	int operando_1;
	int operando_2;
	char operador;
	int resultado;
} Operacao;


typedef struct {
	Operacao entradas[HISTORICO_MAX];
	int total;
} Historico;

void iniciar();
void adicionar_historico();
void imprimir_historico();

#endif
