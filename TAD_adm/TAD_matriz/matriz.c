#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

tMatriz *CriaMatriz(int linhas, int colunas)
{
    tMatriz *m = (tMatriz *)malloc(sizeof(tMatriz));
    m->linhas = linhas;
    m->colunas = colunas;
    m->valores = (int *)calloc(m->linhas * m->colunas, sizeof(int));
    return m;
}

tMatriz *LeMatriz()
{
    int l, c, valor;
    scanf("%d%d", &(l), &(c));
    tMatriz *m = CriaMatriz(l, c);
    for (int i = 0; i < m->linhas; i++)
    {
        for (int j = 0; j < m->colunas; j++)
        {
            scanf("%d", &valor);
            AlteraElementoMatriz(m, i, j, valor);
        }
    }
    return m;
}

void FinalizaMatriz(tMatriz *m)
{
    free(m->valores);
    free(m);
}

void AlteraElementoMatriz(tMatriz *m, int l, int c, int valor)
{
    *(m->valores + m->colunas * l + c) = valor;
}

int ObtemElementoMatriz(tMatriz *m, int l, int c)
{
    return *(m->valores + m->colunas * l + c);
}

void ObtemDimensoesMatriz(tMatriz *m, int *linhas, int *colunas)
{
    *linhas = m->linhas;
    *colunas = m->colunas;
}

void SomaMatriz(tMatriz *m1, tMatriz *m2, tMatriz *mSaida)
{
    for (int i = 0; i < m1->linhas; i++)
    {
        for (int j = 0; j < m1->colunas; j++)
        {
            int valorM1 = ObtemElementoMatriz(m1, i, j);
            int valorM2 = ObtemElementoMatriz(m2, i, j);
            AlteraElementoMatriz(mSaida, i, j, valorM1 + valorM2);
        }
    }
}

void ImprimirMatriz(tMatriz *m)
{
    for (int i = 0; i < m->linhas; i++)
    {
        for (int j = 0; j < m->colunas; j++)
        {
            int valor = ObtemElementoMatriz(m, i, j);
            printf("%d ", valor);
        }
        printf("\n");
    }
}
