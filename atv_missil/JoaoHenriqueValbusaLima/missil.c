#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "missil.h"

struct _tMissil
{
    int Alvo_x;
    int Alvo_y;
    int forca;
    int id;
};

/***
Le missil da entrada padrao e retorna um missil valido alocado dinamicamente
"M #ID #Mx #My #F", sendo
#ID o ID do missil em inteiro
#Mx a coordenada X de ataque do missil em inteiro 
#My a coordenada Y de ataque do missil em inteiro 
#F a forca de ataque do missil em inteiro
*/
tMissil *leMissil()
{
    tMissil *missil = malloc(sizeof(tMissil));
    scanf("%*c %d %d %d %d%*c", &missil->id, &missil->Alvo_x, &missil->Alvo_y, &missil->forca);
    return missil;
}

/***
Dado um missil valido, imprime suas informacoes
"Missil(#ID): (#Mx,#My)->#F", sendo as informacoes conforme definido acima
*/
void imprimeMissil(tMissil* m)
{
    printf("Missil(%d): (%d,%d)->%d", m->id, m->Alvo_x, m->Alvo_y, m->forca);
}

/***
Dado um missil valido, libera sua memoria alocada dinamicamente
*/
void liberaMissil(tMissil* m)
{
    free(m);
}

/***
Dado um missil valido, retorna sua coordenada X
*/
int obtemCoorXMissil(tMissil* m)
{
    return m->Alvo_x;
}

/***
Dado um missil valido, retorna sua coordenada Y
*/
int obtemCoorYMissil(tMissil* m)
{
    return m->Alvo_y;
}

/***
Dado um missil valido, retorna sua forca
*/
int obtemForcaMissil(tMissil* m)
{
    return m->forca;
}

/***
Dado um missil valido, atualiza sua forca com o valor informado em f
*/
void atualizaForcaMissil(tMissil* m, int f)
{
    m->forca = f;
}