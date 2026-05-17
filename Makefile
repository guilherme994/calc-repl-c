CC := gcc
CFLAGS := -Wall -Wextra -std=c11 -Iinclude
SRCDIR := src
TARGET := calc

$(TARGET): ./src/main.o	./src/parser.o	./src/operacoes.o	./src/historico.o
	$(CC) $(CFLAGS) ./src/main.o ./src/parser.o ./src/operacoes.o ./src/historico.o -o $@
main.o:	./src/main.c
	$(CC) $(CFLAGS) -c ./src/main.c 
parser.o:	./src/parser.c
	$(CC) $(CFLAGS) -c ./src/parser.c
operacoes.o:	./src/operacoes.c
	$(CC) $(CFLAGS) -c ./src/operacoes.c
histocio.o :	./src/historico.c
	$(CC) $(CFLAGS) -c ./src/historico.c

clean:
	rm -f $(TARGET)  $(SRCDIR)/*.o

