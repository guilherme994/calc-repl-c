#include "../include/historico.h"
#include <stdio.h>
#include <string.h>

void iniciar(Historico* historico) {
	historico->total = 0;
}

void adicionar_historico(Historico* historico, int n_1, int n_2, int resultado, char* operador) {
	Operacao* operacao = &historico->entradas[historico->total];
	strcpy(&operacao->operador, operador);
	operacao->operando_1 = n_1;
	operacao->operando_2 = n_2;
	operacao->resultado = resultado;
	historico->total++;
}

void imprimir_historico(Historico* historico) {
	printf("Resultado obtido nos calculos anteriores:\n");
	for(int i = 0; i < historico->total ; i++){
		printf("%d %c %d = %d\n", historico->entradas[i].operando_1,  historico->entradas[i].operador,  historico->entradas[i].operando_2,  historico->entradas[i].resultado);
	}
}

