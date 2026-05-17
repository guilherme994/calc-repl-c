# calc-repl-c

Calculadora interativa em C com histórico de operações. Funciona como REPL (read-eval-print loop): você digita uma expressão, ela calcula e guarda o resultado.

Segundo projeto da minha trilha de estudos em C com foco em firmware/embarcados. Sequência do [calc-cli-c](https://github.com/guilherme994/miniprojeto), agora com leitura de stdin, struct para representar operações e armazenamento em array fixo (sem `malloc`).

## Demonstração

```
$ ./calc
> 10 + 5
10 + 5 = 15
> 7 x 3
7 x 3 = 21
> h
10 + 5 = 15
7 x 3 = 21
> q
Finalizando...
```

## Comandos

- `<num> <op> <num>` — executa a operação.
- `h` — imprime o histórico de operações da sessão.
- `q` — encerra o programa.

Operadores suportados: `+`, `-`, `x`, `/`. Uso `x` em vez de `*` para manter consistência com a versão CLI anterior.

## Build

Requer `gcc` e `make`. Testado em Linux (Arch via WSL2).

```
make           # compila e gera ./calc
make clean     # remove .o e binário
```

## Estrutura

```
calc-repl-c/
├── include/
│   ├── historico.h
│   ├── operacoes.h
│   └── parser.h
└── src/
    ├── main.c        — REPL loop, dispatch de comandos
    ├── historico.c   — armazenamento e impressão do histórico
    ├── operacoes.c   — aritmética pura
    └── parser.c      — string → operandos + operador
```

## Decisões de design

- **Histórico em array fixo (`HIST_MAX = 100`), sem `malloc`.** Quando enche, entra em loop voltando para a posição 0.
- **`parse_int` e funções de parser retornam status via `int`, resultado via ponteiro.** Permite separar erro de valor.
- **`const char *` nas entradas de parser.** A função promete não modificar a string original.
- **Tratamento de divisão por zero no `main.c`.** `operacoes.c` é matemática pura; decisões de domínio (como reagir a erro) ficam na camada que tem contexto.

## Limitações conhecidas

- Apenas inteiros — não suporta ponto flutuante.
- Histórico não é persistente entre execuções.
- Apenas operações binárias simples; sem precedência ou expressões compostas.

## Próximos passos possíveis

- Suporte a `float`/`double`.
- Persistir histórico em arquivo.
- Comando `c` para limpar histórico.
