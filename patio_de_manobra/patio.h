#ifndef patio_h
#define patio_h
#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>


void trem_inicia(Pilha* entrada, int *variavel_externa, Pilha* saida);
void trem_imprime(Pilha* trem);
void filas_imprime(Pilha** fila, int x);
void imprime_tudo (Pilha* entrada, Pilha** fila, int x, Pilha* saida);

//retorna x patios de tamanho m
Pilha** fila_cria_aloca(int *x, int *m);

//retorna primeiro patio com espaco disponivel; x: qtd de patios; m: tam dos patios
Pilha* fila_disponivel(Pilha** fila, int *x, int m);

//retorna a fila que tiver o maior valor
Pilha* fila_maior(Pilha** fila, int x, int m);

//retorna se as filas estao vazias
int filas_vazias(Pilha** fila, int x);

void patio_organiza (Pilha* entrada, Pilha** fila, int* x, int m, Pilha* saida);

#endif // patio_h

