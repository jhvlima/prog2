#ifndef _ELEMENTO_CONTAINER_H
#define _ELEMENTO_CONTAINER_H

typedef void (*FptrFinalizaElemento)(void* elem);
typedef int (*FptrColisaoElemento)(void* elem, int x, int y);
typedef void (*FptrTrataColisaoElemento)(void* elem);
typedef void (*FptrImprimeElemento)(void* elem);


typedef struct _tElementoContainer tElementoContainer;

//Cria um ElementoCOntainer
tElementoContainer * CriaElementoContainer( void * dado, 
                                            FptrFinalizaElemento funcFinalizaElemento, 
                                            FptrColisaoElemento funcColisaoElemento,
                                            FptrTrataColisaoElemento funcTrataColisaoElemento,
                                            FptrImprimeElemento funcImprimeElemento);

//Finaliza um ElementoCOntainer
void FinalizaElementoContainer(tElementoContainer * e);

//Verifica a colisao de um elemento com a posicao informada
int ColisaoElementoContainer(tElementoContainer * e, int x, int y);

//Trata a colisao de um elemento
int TrataColisaoElementoContainer(tElementoContainer * e);

//Imprime um elemento
void ImprimeElementoContainer(tElementoContainer * e);

#endif
