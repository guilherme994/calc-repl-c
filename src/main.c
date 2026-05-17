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
	printf("Calculadora REPL — digite 'NUM OP NUM', 'i' p/ historico, 'q' p/ sair.\n");
	while(1) {
		fprintf(stderr,">");
		fgets(text, sizeof(text), stdin);
		parser(text, num_1, num_2, ope);

		if(!strcmp(num_1, "q")) {
			printf("Finalizando...\n");
			return 0;
		}
		else if(!strcmp(num_1, "i")) imprimir_historico(&historico);	
		else {
			parser_operator(ope,&op);
			if(parser_num(num_1, &n_1) == 0 && parser_num(num_2, &n_2) == 0){
				switch (op) {
					case '+': 
						resultado = soma(n_1, n_2);
						adicionar_historico(&historico, n_1, n_2, resultado, op);
						printf("%d %c %d = %d\n", n_1, op, n_2, resultado);
						break;
					case '-': 
						resultado = subtrai(n_1, n_2);
						adicionar_historico(&historico, n_1, n_2, resultado, op);
						printf("%d %c %d = %d\n", n_1, op, n_2, resultado);
						break;
					case 'x': 
						resultado = multiplica(n_1, n_2);
						adicionar_historico(&historico, n_1, n_2, resultado, op);
						printf("%d %c %d = %d\n", n_1, op, n_2, resultado);
						break;
					case '/': 
						if(n_2 != 0){
							resultado = divide(n_1, n_2);	
							adicionar_historico(&historico, n_1, n_2, resultado, op);
							printf("%d %c %d = %d\n", n_1, op, n_2, resultado);
							break;
						}
						else{
							printf("Para divisao o segundo operando nao pose ser igual a 0.\n");
							break;
						}
					default:
						printf("O operador inserido nao e valido.\nDeve conter o seguinte formato 'NUMERO' espaco 'OPERADOR' espaco 'NUMERO'.\nOperadores validos '+', '-', '/', 'x'.\n");
						break;
				}
			}
			else {
				printf("Os operandos inseridos nao sao validos.\n");
			}
		}
		op = '\0';
	}
	return 0;
}
