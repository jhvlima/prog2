#ifndef _MISSIL
#define _MISSIL

typedef struct _tMissil tMissil;

/***
Le missil da entrada padrao e retorna um missil valido alocado dinamicamente
"M #ID #Mx #My #F", sendo
#ID o ID do missil em inteiro
#Mx a coordenada X de ataque do missil em inteiro 
#My a coordenada Y de ataque do missil em inteiro 
#F a forca de ataque do missil em inteiro
*/
tMissil * leMissil();

/***
Dado um missil valido, imprime suas informacoes
"Missil(#ID): (#Mx,#My)->#F", sendo as informacoes conforme definido acima
*/
void imprimeMissil(tMissil*);

/***
Dado um missil valido, libera sua memoria alocada dinamicamente
*/
void liberaMissil(tMissil*);

/***
Dado um missil valido, retorna sua coordenada X
*/
int obtemCoorXMissil(tMissil*);

/***
Dado um missil valido, retorna sua coordenada Y
*/
int obtemCoorYMissil(tMissil*);

/***
Dado um missil valido, retorna sua forca
*/
int obtemForcaMissil(tMissil*);

/***
Dado um missil valido, atualiza sua forca com o valor informado em f
*/
void atualizaForcaMissil(tMissil*, int f);


#endif