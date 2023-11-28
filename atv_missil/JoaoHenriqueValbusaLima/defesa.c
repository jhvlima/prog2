#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "defesa.h"

struct _tDefesa
{
    char tipo;
    int centro_x;
    int centro_y;
    float alcance;
    int poder;
    int numero_amo;
    int id;
    // FptrEstaNaRegiao func; // 
};

/***
Le defesa da entrada padrao e retorna uma defesa valida alocada dinamicamente e com ID informado em id
"D #Dx #Dy #T #A #P #M", sendo
#Dx a coordenada X da defesa em inteiro
#Dy a coordenada Y da defesa em inteiro
#T o tipo da defesa em caractere
#A o alcance da defesa em inteiro
#P o poder de defesa em inteiro
#M o numero de misseis de defesa em inteiro
*/
tDefesa *leDefesa(int id)
{
    tDefesa *defesa = malloc(sizeof(tDefesa));
    scanf("D %d %d %*c%c %d %d", &defesa->centro_x, &defesa->centro_y, &defesa->tipo, &defesa->alcance, &defesa->poder, &defesa->numero_amo);
    defesa->id = id;
    return defesa;
}

/***
Dado uma defesa valida, imprime suas informacoes
"Defesa(#T-#ID): #M" sendo #ID o id da defesa e as outras informacoes conforme definido acima
*/
void imprimeDefesa(tDefesa * d)
{
    printf("Defesa(%c-%d): %d", d->tipo, d->id, d->numero_amo);
}

/***
Dado uma defesa valida, libera sua memoria alocada dinamicamente
*/
void liberaDefesa(tDefesa* d)
{
    free(d);
}

/***
Dado uma defesa valida, retorna o seu tipo
*/
char obtemTipoDefesa(tDefesa *d)
{
    return d->tipo;
}

/***
Dado uma defesa valida, retorna a sua coordenada X
*/
int obtemPosXDefesa(tDefesa *d)
{
    return d->centro_x;
}

/***
Dado uma defesa valida, retorna a sua coordenada Y
*/
int obtemPosYDefesa(tDefesa *d)
{
    return d->centro_y;
}

/***
Dado uma defesa valida, retorna o seu alcance
*/
int obtemAlcanceDefesa(tDefesa *d){
    return d->alcance;
}

/***
Dado uma defesa valida, define sua funcao de defesa com a informada em func
*/
void defineFuncaoDefesa(tDefesa* d, FptrEstaNaRegiao func)
{
    //d->func = func;//
}

/***
Dado uma defesa d valida, retorna verdadeiro se a posicao de ataque informada por posXAta e posYAta
esta na regiao de defesa considerando a funcao de defesa da defesa d
*/
int estaNaRegiaoDefendidaDefesa(tDefesa* d, int posXAta, int posYAta)
{
    //d->func(d, posXAta, posYAta);//
    if (obtemTipoDefesa(d) == 'C')
    {
        if(sqrt(pow(d->alcance - d->centro_x, 2) + pow(d->alcance - d->centro_y, 2)) > sqrt(pow(d->alcance - posXAta, 2) + pow(d->alcance - posYAta, 2)))
        {
            return 1;
        }
        return 0;
    }
    if (obtemTipoDefesa(d) == 'Q')
    {
        if(sqrt(pow(d->alcance - d->centro_x, 2) + pow(d->alcance - d->centro_y, 2)) > sqrt(pow(d->alcance - posXAta, 2) + pow(d->alcance - posYAta, 2)))
        {
            return 1;
        }
        return 0;
    }
    
}

/***
Dado uma defesa d valida, processa um ataque com a forca informada como parametro e 
atualiza o estado da defesa. Considere que o ataque ja esta na regiao de defesa.
Retorna a forca restante de ataque apos a defesa.
*/
int defendeAtaque(tDefesa* d, int forca);