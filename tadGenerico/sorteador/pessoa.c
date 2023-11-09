#include "pessoa.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _tPessoa
{
    int idade;
    char *nome;
};

tPessoa *CriaPessoa(char nome[], int idade)
{
    tPessoa *pess = malloc(sizeof(tPessoa));
    pess->idade = idade;
    pess->nome = malloc((strlen(nome) + 1) * sizeof(char));
    strcpy(pess->nome, nome);
    return pess;
}

void FinalizaPessoa(tPessoa *pess)
{
    free(pess->nome);
    free(pess);
}

void ImprimePessoa(tPessoa *pess)
{
    printf("%s tem %d anos.\n", pess->nome, pess->idade);
}