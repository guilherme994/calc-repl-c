#ifndef HISTORICO_H
#define HISTORICO_H

#include <stdbool.h>
#define HISTORICO_MAX 6

typedef struct {
	int operando_1;
	int operando_2;
	char operador;
	int resultado;
} Operacao;

typedef struct {
	Operacao entradas[HISTORICO_MAX];
	int total;
	bool deu_volta;
} Historico;

void iniciar(Historico* historico);
void adicionar_historico(Historico* historico, int n_1, int n_2, int resultado, char operador); 
void imprimir_historico(Historico* historico);

#endif
