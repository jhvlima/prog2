#include "sorteador.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct _tSorteador
{
    int quantidadeElementos;
    void **elementos;
};

tSorteador *CriaSorteador(int usarSemente)
{
    tSorteador *sort = malloc(sizeof(tSorteador));
    sort->quantidadeElementos = 0;
    sort->elementos = NULL;
    if (usarSemente)
        srand((unsigned)time(NULL));
    return sort;
}

void FinalizaSorteador(tSorteador *sort)
{
    if (sort->elementos)
        free(sort->elementos);
    free(sort);
}

void AdicionaElementoSorteador(tSorteador *sort, void *elem)
{
    (sort->quantidadeElementos)++;
    sort->elementos = realloc(sort->elementos, sort->quantidadeElementos * sizeof(void *));
    sort->elementos[sort->quantidadeElementos - 1] = elem;
}

void *SorteiaElementoSorteador(tSorteador *sort)
{
    void *elem;
    // Gera um indice aleatorio entre zero e quantidadeElementos-1
    int indiceAleatorio = rand() % sort->quantidadeElementos;
    elem = sort->elementos[indiceAleatorio];

    // Remove este elementos
    for (int i = indiceAleatorio; i < sort->quantidadeElementos - 1; i++)
    {
        sort->elementos[i] = sort->elementos[i + 1];
    }
    (sort->quantidadeElementos)--;

    if (sort->quantidadeElementos)
    {
        sort->elementos = realloc(sort->elementos, sort->quantidadeElementos * sizeof(void *));
    }
    else
    {
        free(sort->elementos);
        sort->elementos = NULL;
    }
    return elem;
}

int TemElementosSorteador(tSorteador *sort)
{
    return sort->quantidadeElementos;
}
