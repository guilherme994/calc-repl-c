#include "../include/historico.h"
#include <stdio.h>

void iniciar(){
	Historico historico;
	historico.total = 0;
}

void adicionar_historico(Historico* historico, int n_1, int n_2, int resultado, char* operador) {
	
	Operacao* operacao = &historico->entradas[historico->total];

	snprintf(&operacao->operador, sizeof(operacao->operador), "%s", operador);
	operacao->operando_1 = n_1;
	operacao->operando_2 = n_2;
	operacao->resultado = resultado;
}

void imprimir_historico() {

}

