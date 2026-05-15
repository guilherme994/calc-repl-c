#include "../include/historico.h"
#include "../include/operacoes.h"
#include "../include/parser.h"

#include <stdio.h>

int main(void) {

	char text[50];
	char op;
	int n_1, n_2, resultado;
	while(1) {
		fgets(text, sizeof(text), stdin);
		

		if(parser(text, &n_1, &n_2, &op)) return 0;
		
		switch (op) {
			case '+': resultado = soma(n_1, n_2);	break;
			case '-': resultado = subtrai(n_1, n_2);	break;
			case 'x': resultado = multiplica(n_1, n_2);	break;
			case '/': resultado = divide(n_1, n_2);	break;
		}

		printf("%d %c %d = %d\n", n_1, op, n_2, resultado);
	}
	
	return 0;
}
