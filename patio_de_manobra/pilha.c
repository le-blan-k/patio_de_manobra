#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>


Pilha* pilha_cria (void)
{
    Pilha* novo = (Pilha*)malloc(sizeof(Pilha));
    novo->n = 0;
    novo->vet = NULL;
    return novo;
}

void pilha_aloca (Pilha* p, int n)
{
    p->vet = (int*)malloc(n*sizeof(int));
}

int pilha_vazia (Pilha* p)
{
    if(p->n == 0)
        return 1;
    return 0;
}

int pilha_cheia (Pilha* p, int n)
{
    if(p->n == n)
        return 1;
    return 0;
}

void pilha_push (Pilha* p, int v)
{
    p->vet[p->n] = v;
    p->n++;
}

int pilha_pop (Pilha* p)
{
    int val = NULL;
    if(p->n > 0 )
    {
        p->n--;
        val = p->vet[p->n];
        p->vet[p->n] = NULL;
    }
    return val;
}

void pilha_push_pop (Pilha* a, Pilha* b)
{
    pilha_push(a, pilha_pop(b));
}


int pilha_topo (Pilha* p)
{
    if(p->n <= 0)
        return NULL;
    return p->vet[p->n-1];
}

//retorna maior valor na pilha
int pilha_maior(Pilha* p)
{
    int i, maior = NULL;
    for(i=0; i<p->n; i++)
    {
        if(p->vet[i] > maior)
        {
            maior = p->vet[i];
        }
    }
    return maior;
}


void pilha_libera (Pilha* p)
{
    free(p->vet);
    free(p);
}
