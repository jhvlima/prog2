#include <stdio.h>
#include <stdlib.h>
#include "cidade.h"
#include "defesa.h"
#include "missil.h"

struct _tCidade 
{
    int altura;
    int largura;
    int num_defesas;
    tDefesa **defesa;
    int dano_recebido;
    int dano_pot;
};

/***
Le cidade da entrada padrao e retorna uma cidade valida alocada dinamicamente
"C #L #A #d", sendo
#L a largura da cidade em inteiro
#A a altura da cidade em inteiro 
#d o numero de defesas da cidade em inteiro 
*/
tCidade * leCidade()
{
    tCidade *c = malloc(sizeof(tCidade));
    scanf("%*c %d %d %d", &c->altura, &c->largura, &c->num_defesas);
    tDefesa **defesas = malloc(sizeof(tDefesa*)*c->num_defesas);
    c->dano_pot = 0;
    c->dano_recebido = 0;
    return c;
}

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
void imprimeCidade(tCidade* c)
{
    printf("Cidade:\n");
    printf("-Tamanho:[%d, %d]\n", c->largura , c->altura);
    printf("-Dano potencial: %d\n", c->dano_pot);
    printf("-Dano Recebido: #Dr\n", c->dano_recebido);
}

/***
Dado uma cidade valida, libera sua memoria alocada dinamicamente
*/
void liberaCidade(tCidade* c)
{
    for (int i = 0; i < c->num_defesas; i++)
    {
        liberaDefesa(c->defesa[i]);
    }
    free(c);
}

/***
Dado uma cidade valida, retorna a quantidade de defesas
*/
int obtemQtdDefesasCidade(tCidade* c)
{
    return c->num_defesas;
}

/***
Dado uma cidade valida, adiciaona a defesa d a sua lista de defesas
*/
void adicionaDefesaCidade(tCidade * c, tDefesa * d)
{
    c->num_defesas++;
    c->defesa = realloc(c->defesa, c->num_defesas * (sizeof(tDefesa*)));
    c->defesa[c->num_defesas -1] = d;
}

/***
Dado uma cidade valida, retorna verdadeiro se a posicao de ataque do missil m estiver dentro da cidade
e falso caso contrario
*/
int dentroDaCidade(tCidade * c, tMissil *m)
{
    if (obtemCoorYMissil(m) > c->largura || obtemCoorYMissil(m) > c->altura)
    {
        return 0;
    }
    return 1;
    
}

/***
Dado uma cidade valida, processa o ataque referente ao missil m
atualizando o estado das defesas e do missil
e retorna 
0 caso o missil tenha sido neutralizado
-1 caso o missil nao tenha sido defendido
ou a forca restante do missil caso contrario
*/
int processaAtaqueCidade(tCidade* c, tMissil * m)
{
    if(dentroDaCidade(c, m))
    {
        int atq = 0, def = 0;
        for (int i = 0; i < c->num_defesas; i++)
        {
            if(estaNaRegiaoDefendidaDefesa(c->defesa[i], obtemCoorXMissil(m), obtemCoorYMissil(m)))
            {
                def = 1;
                atq = defendeAtaque(c->defesa[i], obtemForcaMissil(m));
            }
        }
        if (def)
        {
            c->dano_recebido = c->dano_recebido + atq;
        }
        else
        {
            c->dano_recebido = c->dano_recebido + obtemForcaMissil(m);
        }
        c->dano_pot = c->dano_pot + obtemForcaMissil(m);   
    }
    return -1;
}