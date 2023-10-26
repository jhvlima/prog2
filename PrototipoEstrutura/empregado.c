#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empregado.h"

typedef enum
{
    COLABORADOR = 0,
    GERENTE = 1,
    DIRETOR = 2
} FUNCAO;

struct _tEmpregado
{
    char nome[200];
    FUNCAO funcao;
    tEmpregado *superior;
};

tEmpregado *CriaEmpregado(char *nome, FUNCAO func)
{
    tEmpregado *e = (tEmpregado *)malloc(sizeof(tEmpregado));
    strcpy(e->nome, nome);
    e->funcao = func;
    e->superior = NULL;
    return e;
}

tEmpregado *LeEmpregado()
{
    char nome[200];
    int funcao;
    scanf("%s %d", nome, &funcao);
    return CriaEmpregado(nome, funcao);
}

void FinalizaEmpregado(tEmpregado *e)
{
    free(e);
}

int EhColaboradorEmpregado(tEmpregado *e)
{
    return e->funcao == COLABORADOR;
}

int EhGerenteEmpregado(tEmpregado *e)
{
    return e->funcao == GERENTE;
}

int EhDiretorEmpregado(tEmpregado *e)
{
    return e->funcao == DIRETOR;
}
void AtribuiSuperiorEmpregado(tEmpregado *e, tEmpregado *sup)
{
    e->superior = sup;
}

void ImprimirFuncao(FUNCAO funcao)
{

    if (funcao == COLABORADOR)
        printf("Colaborador");
    else if (funcao == GERENTE)
        printf("Gerente");
    else if (funcao == DIRETOR)
        printf("Diretor");
    else
    {
        printf("Funcao inexistente!\n");
        exit(1);
    }
}

void ImprimirEmpregado(tEmpregado *e)
{
    printf("Empregado: %s eh ", e->nome);
    ImprimirFuncao(e->funcao);
    printf("\n");
}

void ImprimirSuperioresEmpregado(tEmpregado *e)
{
    int temSuperior = 0;
    tEmpregado *superior;
    printf("Lista de superiores de: %s\n", e->nome);
    superior = e->superior;

    // Verifica primeiro nivel de superior
    if (superior != NULL)
    {
        printf("\t");
        ImprimirEmpregado(superior);
        temSuperior++;
        superior = superior->superior;
    }

    // Verifica segundo nivel de superior
    if (superior != NULL)
    {
        printf("\t");
        ImprimirEmpregado(superior);
        temSuperior++;
        superior = superior->superior;
    }

    if (!temSuperior)
        printf("\tNao tem superior!\n");
}