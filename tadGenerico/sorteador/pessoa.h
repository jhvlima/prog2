#ifndef _PESSOA_H
#define _PESSOA_H

typedef struct _tPessoa tPessoa;

//Cria uma pessoa
tPessoa * CriaPessoa(char nome[], int idade);

//Finaliza uma pessoa
void FinalizaPessoa(tPessoa * pess);

//Imprime uma pessoa
void ImprimePessoa(tPessoa * pess);

#endif
