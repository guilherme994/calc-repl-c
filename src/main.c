#include "../include/historico.h"
#include "../include/operacoes.h"
#include "../include/parser.h"

#include <stdio.h>
#include <string.h>

int main(void) {

	char op;
	int n_1, n_2, resultado;
	char text [50], num_1[20], num_2[20], ope[20];

	Historico historico;
	iniciar(&historico);

	while(1) {
		fgets(text, sizeof(text), stdin);
		parser(text, num_1, num_2, ope);
//		printf("%s %s %s\n", num_1, ope, num_2);

		if(!strcmp(num_1, "q")) return 0;
		else if(!strcmp(num_1, "i")) imprimir_historico(&historico);	
		else {
			parser_num(num_1, &n_1);
			parser_num(num_2, &n_2);
			parser_operator(ope,&op);
			switch (op) {
				case '+': resultado = soma(n_1, n_2);	adicionar_historico(&historico,n_1,n_2,resultado,&op);	break;
				case '-': resultado = subtrai(n_1, n_2);	adicionar_historico(&historico,n_1,n_2,resultado,&op);	break;
				case 'x': resultado = multiplica(n_1, n_2);	adicionar_historico(&historico,n_1,n_2,resultado,&op);	 break;
				case '/': resultado = divide(n_1, n_2);	adicionar_historico(&historico,n_1,n_2,resultado,&op);	break;
			}

			printf("%d %c %d = %d\n", n_1, op, n_2, resultado);
		}
	}
	return 0;
}
