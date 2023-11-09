#ifndef _RETANGULO_H
#define _RETANGULO_H

typedef struct _tRetangulo tRetangulo;

//Cria um retangulo
tRetangulo * CriaRetangulo(int id, int xInfEsq, int yInfEsq, int xSupDir, int ySupDir);

//Finaliza um retangulo
void FinalizaRetangulo(void * r);

//Imprime um retangulo
void ImprimeRetangulo(void * r);

//Verifica colisao do retangulo com a posicao informada
int ColisaoRetangulo(void* elem, int x, int y);

//Trata uma colisao com o retangulo
void TratarColisaoRetangulo(void* elem);

#endif
