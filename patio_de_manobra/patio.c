#include "pilha.h"
#include "patio.h"
#include <stdio.h>
#include <stdlib.h>

void trem_inicia(Pilha* entrada, int *variavel_externa, Pilha* saida)
{
    int i, a;
    printf("Digite quantos elementos tem na entrada: ");
    scanf("%d", variavel_externa);
    pilha_aloca(entrada, *variavel_externa);
    pilha_aloca(saida, *variavel_externa);
    for(i=0; i < *variavel_externa; i++)
    {
        printf("Digite o elemento de indice %d: ", i);
        scanf("%d", &a);
        pilha_push(entrada, a);
    }
}

void trem_imprime(Pilha* trem)
{
    int i;
    printf("\nVagoes: %d\n", trem->n);
    printf("Ordem: ");
    for(i=0; i< trem->n; i++){
        printf("%d ", trem->vet[i]);
    }
    printf("\n");
}

void filas_imprime(Pilha** fila, int x)
{
    int i, maior;
    printf("\nFilas de espera: ");
    for(i=0; i< x; i++)
    {
        printf("\n\tFila %d: ", i);
        trem_imprime(fila[i]);
        maior = pilha_maior(fila[i]);
        printf("Maior valor na fila %d: %d\n", i, maior);
    }
}

void imprime_tudo (Pilha* entrada, Pilha** fila, int x, Pilha* saida)
{
    system("cls");
    trem_imprime(entrada);
    filas_imprime(fila, x);
    trem_imprime(saida);
    system("pause");
}

//retorna x filas de tamanho m
Pilha** fila_cria_aloca(int *x, int *m)
{
    printf("\nDigite quantas filas tem: ");
    scanf("%d", x);
    printf("Digite o tamanho de cada fila: ");
    scanf("%d", m);
    Pilha** novo = (Pilha**)malloc((*x)*sizeof(Pilha*));
    int i;
    for(i=0;i<(*x);i++)
    {
        novo[i] = pilha_cria();
        pilha_aloca(novo[i], *m);
    }
    return novo;
}

Pilha* fila_disponivel(Pilha** fila, int *x, int m)
{
    int i;
    for(i=0; i<*x; i++)
    {
        if( !pilha_cheia(fila[i], m) )
        {
            return fila[i];
        }
    }
    printf("\nNenhuma fila disponivel, criando mais uma... \n");
    system("pause");
    x[0]++;
    *fila = (Pilha**)realloc(*fila,(*x)*sizeof(Pilha*));
    fila[i]=pilha_cria();
    pilha_aloca(fila[i], m);
    return fila_disponivel(fila, x, m);
}

//retorna a fila que tiver o maior valor
Pilha* fila_maior(Pilha** fila, int x, int m)
{
    int i;
    Pilha* maior = pilha_cria();
    maior = fila[x-1];
    for(i=0; i<x; i++)
    {
        if( i == (x-1) )
        {
            return maior;
        }
        else if( pilha_maior(fila[i]) > pilha_maior(fila[i+1])  )
        {
            maior = fila[i];
        }
    }

}

//retorna se as filas estao vazias
int filas_vazias(Pilha** fila, int x)
{
    int i, resultado = 1;
    for(i=0; i<x; i++)
    {
        resultado = pilha_vazia(fila[i]);
        if(resultado == 0)
        {
            return resultado;
        }
    }
    return resultado;
}


void patio_organiza (Pilha* entrada, Pilha** fila, int* x, int m, Pilha* saida)
{
    while(!pilha_vazia(entrada) || !filas_vazias(fila, *x))
    {
        imprime_tudo(entrada, fila, *x, saida);
        if(pilha_maior(entrada) >= pilha_maior(fila_maior(fila, *x, m)) )
        {
            if(pilha_maior(entrada) == pilha_topo(entrada) )
            {
                pilha_push_pop(saida, entrada);
            }
            else
            {
                pilha_push_pop(fila_disponivel(fila, x, m), entrada);
            }
        } else
        {
            if(pilha_maior(fila_maior(fila, *x, m)) == pilha_topo(fila_maior(fila, *x, m)) )
            {
                pilha_push_pop(saida, fila_maior(fila, *x, m));
            }
            else
            {
                pilha_push_pop(entrada, fila_maior(fila, *x, m));
            }
        }
    }
    imprime_tudo(entrada, fila, *x, saida);
}
