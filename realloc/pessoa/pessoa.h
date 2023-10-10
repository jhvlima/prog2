#ifndef _PESSOA_H
#define _PESSOA_H

typedef struct
{
    char *cpf;
    char *nome;
    int idade;
} tPessoa;

// Le uma pessoa da entrada padrao
tPessoa *LePessoa();

// Destroi uma pessoa
void FinalizaPessoa(tPessoa *p);

// Imprime uma pessoa na saida padrao
void ImprimirPessoa(tPessoa *p);

#endif
