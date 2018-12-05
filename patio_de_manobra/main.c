#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "patio.h"

int main(void)
{
    int n;
    //n vai guardar o tamanho inicial do trem

    int x, m;
    //x vai guardar quantos patios existem
    //m vai guardar o tamanho de cada patio

    Pilha *entrada = pilha_cria();
    Pilha *saida = pilha_cria();
    trem_inicia(entrada, &n, saida);
    Pilha** fila = fila_cria_aloca(&x, &m);
    imprime_tudo(entrada, fila, x, saida);
    patio_organiza(entrada, fila, &x, m, saida);
    puts("Fim de execucao.");
    system("pause");
    return 0;
}
