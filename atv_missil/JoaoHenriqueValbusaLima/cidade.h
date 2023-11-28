#ifndef _CIDADE
#define _CIDADE
#include "defesa.h"
#include "missil.h"

typedef struct _tCidade tCidade;

/***
Le cidade da entrada padrao e retorna uma cidade valida alocada dinamicamente
"C #L #A #d", sendo
#L a largura da cidade em inteiro
#A a altura da cidade em inteiro 
#d o numero de defesas da cidade em inteiro 
*/
tCidade * leCidade();

/***
Dado uma cidade valida, imprime suas informacoes
"Cidade:" em uma linha
"-Tamanho:[#L, #A]" em uma linha 
"-Dano potencial: #Dp" em uma linha
"-Dano Recebido: #Dr" em uma linha
sendo as informacoes # conforme definidas anteriormente e sendo
#Dp o dano potencial 
#Dr o dano efetivamente recebido
*/
void imprimeCidade(tCidade* c);

/***
Dado uma cidade valida, libera sua memoria alocada dinamicamente
*/
void liberaCidade(tCidade* c);

/***
Dado uma cidade valida, retorna a quantidade de defesas
*/
int obtemQtdDefesasCidade(tCidade* c);

/***
Dado uma cidade valida, adiciaona a defesa d a sua lista de defesas
*/
void adicionaDefesaCidade(tCidade * c, tDefesa * d);

/***
Dado uma cidade valida, retorna verdadeiro se a posicao de ataque do missil m estiver dentro da cidade
e falso caso contrario
*/
int dentroDaCidade(tCidade * c, tMissil * m);

/***
Dado uma cidade valida, processa o ataque referente ao missil m
atualizando o estado das defesas e do missil
e retorna 
0 caso o missil tenha sido neutralizado
-1 caso o missil nao tenha sido defendido
ou a forca restante do missil caso contrario
*/
int processaAtaqueCidade(tCidade* c, tMissil * m);

#endif