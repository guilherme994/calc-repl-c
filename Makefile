CC := gcc
CFLAGS := -Wall -Wextra -std=c11
SRCDIR := src

calc: ./src/main.o	./src/parser.o	./src/operacoes.o	./src/historico.o
	$(CC) $(CFLAGS) ./src/main.o ./src/parser.o ./src/operacoes.o ./src/historico.o -o $@
main.o:	./src/main.c	./include/parser.h	./include/operacoes.h	./include/historico.h
	$(CC) $(CFLAGS) -c ./src/main.c 
parser.o:	./include/parser.h	./src/parser.c
	$(CC) $(CFLAGS) -c ./src/parser.c
operacoes.o:	./include/operacoes.h	./src/operacoes.c
	$(CC) $(CFLAGS) -c ./src/operacoes.c
histocio.o :	./include/historico.h	./src/historico.c
	$(CC) $(CFLAGS) -c ./src/historico.c

clean:
	rm -f calc *.o
