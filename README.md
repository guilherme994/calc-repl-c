# Calculadora CLI em C

Calculadora de linha de comando feita como exercício de modularização em C, com headers separados e build via Makefile. Parte da minha trilha de estudos rumo a desenvolvimento de firmware/embarcados.

## Uso

```bash
make
./calc
# Entrada:10 + 5
# Saída:10 + 5 = 15

```

Operações suportadas: `+`, `-`, `x`, `/`. Uso `x` em vez de `*` para evitar expansão de glob pelo shell.

## Estrutura

- `main.c` — entry point, lê o teclado com `fgets`, orquestra parser, operações e historico.
- `parser.{c,h}` — conversão de string para inteiro e identificação do operador.
- `operacoes.{c,h}` — implementação das quatro operações aritméticas.
- `historico.{c,h}` - implementação de struct para armazenar e imprimir os cálculos.
- `Makefile` — build separado por unidade de compilação, com regra `clean`.

## Decisões de design

- **`parse_int` retorna status (`int`) e escreve resultado via ponteiro.** Padrão comum em C de sistema, permite distinguir erro de valor convertido válido.
- **`const char *` nas funções de parser.** A função promete não modificar a string passada.
- **Divisão por zero é checada em `main.c`, não em `operacoes.c`.** O módulo de operações é matemática pura; tratamento de erro de domínio fica na camada que tem contexto pra reagir.

## Build

Requer `gcc` e `make`. Testado em Linux (Arch via WSL2).

```bash
make           # compila
make clean     # remove artefatos
```
