#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pessoa.h"

char *LeNome()
{
    char letra;
    char *nome = NULL;
    int tamanhoNome = 0;

    while (scanf("%c", &letra) == 1 && letra != ',')
    {
        tamanhoNome++;
        nome = (char *)realloc(nome, tamanhoNome);
        nome[tamanhoNome - 1] = letra;
    }
    tamanhoNome++;
    nome = (char *)realloc(nome, tamanhoNome);
    nome[tamanhoNome - 1] = '\0';

    return nome;
}

char *LeCPF()
{
    char digito;
    char *cpf = NULL;
    int tamanhoCPF = 0;

    while (scanf("%c", &digito) == 1 && digito != ',')
    {
        tamanhoCPF++;
        cpf = (char *)realloc(cpf, tamanhoCPF);
        cpf[tamanhoCPF - 1] = digito;
    }
    tamanhoCPF++;
    cpf = (char *)realloc(cpf, tamanhoCPF);
    cpf[tamanhoCPF - 1] = '\0';

    return cpf;
}

tPessoa *LePessoa()
{
    char letra;
    char *nome = NULL;
    int tamanhoNome = 0, idade;
    tPessoa *p = (tPessoa *)malloc(sizeof(tPessoa));

    scanf("%*[^{]"); // Descarta lixo antes da chaves
    scanf("{");      // Consome primeira chave
    p->nome = LeNome();
    p->cpf = LeCPF();
    scanf("%d", &(p->idade));
    scanf("}"); // Consome ultima chave

    return p;
}

void FinalizaPessoa(tPessoa *p)
{
    free(p->nome);
    free(p->cpf);
    free(p);
}

void ImprimirPessoa(tPessoa *p)
{
    printf("\tNome: %s\n", p->nome);
    printf("\tCPF: %s\n", p->cpf);
    printf("\tIdade: %d\n", p->idade);
}
