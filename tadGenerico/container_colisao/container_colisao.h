#ifndef _CONTAINER_COLISAO_H
#define _CONTAINER_COLISAO_H
#include "elemento_container.h"

typedef struct _tContainerColisao tContainerColisao;

//Cria um Container de Colisao
tContainerColisao * CriaContainerColisao();

//Finaliza um Container de Colisao
void FinalizaContainerColisao(tContainerColisao * c);

//Adiciona elemento para ser sorteado
void AdicionaElementoContainerColisao(  tContainerColisao * c, 
                                        void * dado, 
                                        FptrFinalizaElemento funcFinalizaElemento, 
                                        FptrColisaoElemento funcColisaoElemento,
                                        FptrTrataColisaoElemento funcTrataColisaoElemento,
                                        FptrImprimeElemento funcImprimeElemento);

//Verifica colisoes dos elementos com a posicao informada e trata cada uma delas
int VerificaColisaoContainerColisao(tContainerColisao * c, int x, int y);

//Lista elementos do Container
void ListaElementosContainerColisao(tContainerColisao * c);

#endif
