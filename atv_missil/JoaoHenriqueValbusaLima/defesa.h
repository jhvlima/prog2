#ifndef _DEFESA
#define _DEFESA

typedef struct _tDefesa tDefesa;

/***
Prototipo de funcao de defesa para verificar se um ponto de ataque (posXAta,posYAta) 
esta em uma determida regiao coberta pela defesa d
*/
typedef int (*FptrEstaNaRegiao)(tDefesa * d, int posXAta, int posYAta);

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
tDefesa *leDefesa(int id);

/***
Dado uma defesa valida, imprime suas informacoes
"Defesa(#T-#ID): #M" sendo #ID o id da defesa e as outras informacoes conforme definido acima
*/
void imprimeDefesa(tDefesa * d);

/***
Dado uma defesa valida, libera sua memoria alocada dinamicamente
*/
void liberaDefesa(tDefesa*);

/***
Dado uma defesa valida, retorna o seu tipo
*/
char obtemTipoDefesa(tDefesa *d);

/***
Dado uma defesa valida, retorna a sua coordenada X
*/
int obtemPosXDefesa(tDefesa *d);

/***
Dado uma defesa valida, retorna a sua coordenada Y
*/
int obtemPosYDefesa(tDefesa *d);

/***
Dado uma defesa valida, retorna o seu alcance
*/
int obtemAlcanceDefesa(tDefesa *d);

/***
Dado uma defesa valida, define sua funcao de defesa com a informada em func
*/
void defineFuncaoDefesa(tDefesa* d, FptrEstaNaRegiao func);

/***
Dado uma defesa d valida, retorna verdadeiro se a posicao de ataque informada por posXAta e posYAta
esta na regiao de defesa considerando a funcao de defesa da defesa d
*/
int estaNaRegiaoDefendidaDefesa(tDefesa* d, int posXAta, int posYAta);

/***
Dado uma defesa d valida, processa um ataque com a forca informada como parametro e 
atualiza o estado da defesa. Considere que o ataque ja esta na regiao de defesa.
Retorna a forca restante de ataque apos a defesa.
*/
int defendeAtaque(tDefesa* d, int forca);

#endif