#include "../include/historico.h"
#include "../include/operacoes.h"
#include "../include/parser.h"

#include <stdio.h>

int main(void) {

	while(1) {
		char text[50];
		fgets(text, sizeof(text), stdin);
		char op;

		int n_1, n_2, resultado;
		//parserrser_num(&text[0], &n_1);
		//parser_num(&text[4], &n_2);
		
		parser(text, &n_1, &n_2, &op);
		
		printf("%d %c %d\n", n_1, op, n_2);
		switch (op) {
			case '+': resultado = soma(n_1, n_2);	break;
			case '-': resultado = subtrai(n_1, n_2);	break;
			case 'x': resultado = multiplica(n_1, n_2);	break;
			case '/': resultado = divide(n_1, n_2);	break;
		}
		printf("%d\n", resultado);
		break;
	}
	
	return 0;
}
