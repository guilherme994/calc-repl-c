#include "../include/historico.h"
#include "../include/operacoes.h"
#include "../include/parser.h"

#include <stdio.h>

int main(void) {

	while(1) {
		char text[50];
		char a = '-';
		fgets(text, sizeof(text), stdin);
		char op = parser_operator(&text[2]);
		char ope = parser_operator(&a);

		printf("%c\n", op);
		printf("%c\n", ope);

		int n_1, n_2, resultado;
		parser_num(&text[0], &n_1);
		parser_num(&text[4], &n_2);
		printf("%d\n", (n_1 + n_2));
		printf("%d\n", soma(5, 5));
		
		switch (text[2]) {
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
