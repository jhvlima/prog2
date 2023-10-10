#include <stdio.h>
#include <stdlib.h>
#include "pessoa.h"

typedef enum
{
    CADASTRO = 0,
    EXCLUSAO = 1,
    IMPRESSAO = 2,
    SAIR = 3
} OPERACAO;

void ImprimeMenu()
{
    printf("Menu:\n");
    printf("%d - CADASTRO\n", CADASTRO);
    printf("%d - EXCLUSAO\n", EXCLUSAO);
    printf("%d - IMPRESSAO\n", IMPRESSAO);
    printf("%d - SAIR\n", SAIR);
}

void CadastroPessoa(tPessoa ***pessoas, int *numPessoas)
{ // A lista de pessoas (**pessoas) eh passada por referencia, por isso ***pessoas
    tPessoa *pessoa = NULL;
    (*numPessoas)++;                                                           // Incrementa numero de pessoas
    *pessoas = (tPessoa **)realloc(*pessoas, *numPessoas * sizeof(tPessoa *)); // Aumenta tamanho da memoria sem perder os antigos
    pessoa = LePessoa();                                                       // Le a nova pessoa
    (*pessoas)[*numPessoas - 1] = pessoa;                                      // Guarda no novo espaco de memoria
}

void ExcluiPessoa(tPessoa ***pessoas, int *numPessoas)
{
    int indice;
    printf("Digite um indice de uma pessoa para exluir\n");
    scanf("%d", &indice); // Le o indice a ser excluido
    if (indice < 0 || indice >= *numPessoas)
    { // Verifica se o indice eh valido
        printf("Indice de pessoa %d fora do intervalo 0 e %d", indice, *numPessoas);
        return;
    }
    FinalizaPessoa((*pessoas)[indice]); // Libera a memoria da pessoa excluida
    for (int i = indice + 1; i < *numPessoas; i++)
    { // Copia todos que estao acima dela um para baixo
        (*pessoas)[i - 1] = (*pessoas)[i];
    }
    (*numPessoas)--;                                                           // Decrementa o tamanho da lista
    *pessoas = (tPessoa **)realloc(*pessoas, *numPessoas * sizeof(tPessoa *)); // Reduz a memoria sem perder os antigos
}

void LiberaPessoas(tPessoa **pessoas, int numPessoas)
{
    for (int i = 0; i < numPessoas; i++)
    {
        FinalizaPessoa(pessoas[i]);
    }
    free(pessoas);
}

void ImprimePessoas(tPessoa **pessoas, int numPessoas)
{

    if (numPessoas == 0)
    {
        printf("Nao ha pessoas cadastradas!\n");
        return;
    }
    for (int i = 0; i < numPessoas; i++)
    {
        printf("Pessoa %d\n", i);
        ImprimirPessoa(pessoas[i]);
    }
}

int main()
{
    tPessoa **pessoas = NULL; // Lista de pessoas
    int numPessoas = 0;       // NUmero de pessoas da lista
    tPessoa *pessoa = NULL;
    int val;

    ImprimeMenu();
    while (scanf("%d", &val) == 1)
    {
        OPERACAO op = val;
        if (op == CADASTRO)
        {
            CadastroPessoa(&pessoas, &numPessoas);
        }
        else if (op == EXCLUSAO)
        {
            ExcluiPessoa(&pessoas, &numPessoas);
        }
        else if (op == IMPRESSAO)
        {
            ImprimePessoas(pessoas, numPessoas);
        }
        else if (op == SAIR)
        {
            break;
        }
        else
        {
            printf("%d eh uma operacao invalida!\n", op);
            exit(1);
        }
        ImprimeMenu();
    }

    LiberaPessoas(pessoas, numPessoas); // Libera pessoas caso haja alguem na lista
    return 0;
}
