#ifndef pilha_h
#define pilha_h
#include <stdio.h>
#include <stdlib.h>

typedef struct pilha Pilha;
struct pilha{
    int n; //numero de elementos
    int* vet;
};

Pilha* pilha_cria (void);

//aloca p->vet[n];
void pilha_aloca (Pilha* p, int n);

int pilha_vazia (Pilha* p);

int pilha_cheia (Pilha* p, int n);

void pilha_push (Pilha* p, int v);

int pilha_pop (Pilha* p);

void pilha_push_pop (Pilha* a, Pilha* b);

int pilha_topo (Pilha* p);

//retorna maior valor na pilha;
int pilha_maior(Pilha* p);


void pilha_libera (Pilha* p);


#endif // pilha_h
