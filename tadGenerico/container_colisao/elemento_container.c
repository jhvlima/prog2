#include "elemento_container.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _tElementoContainer{
    void* dado; 
    
    FptrFinalizaElemento funcFinalizaElemento;
    FptrColisaoElemento funcColisaoElemento;
    FptrTrataColisaoElemento funcTrataColisaoElemento;
    FptrImprimeElemento funcImprimeElemento;
};

tElementoContainer * CriaElementoContainer( void * dado, 
                                            FptrFinalizaElemento funcFinalizaElemento, 
                                            FptrColisaoElemento funcColisaoElemento,
                                            FptrTrataColisaoElemento funcTrataColisaoElemento,
                                            FptrImprimeElemento funcImprimeElemento){
	tElementoContainer * e = malloc(sizeof(tElementoContainer));
    e->dado = dado;
    e->funcFinalizaElemento = funcFinalizaElemento;
    e->funcColisaoElemento = funcColisaoElemento;
    e->funcTrataColisaoElemento = funcTrataColisaoElemento;
    e->funcImprimeElemento = funcImprimeElemento;
	return e;
}

void FinalizaElementoContainer(tElementoContainer * e){
    //Libera memoria do dado cadastrado no container
    e->funcFinalizaElemento(e->dado);
    //Libera memoria do elemento
    free(e);    
}

int ColisaoElementoContainer(tElementoContainer * e, int x, int y){
    return e->funcColisaoElemento(e->dado, x, y);
}

int TrataColisaoElementoContainer(tElementoContainer * e){
    e->funcTrataColisaoElemento(e->dado);
}

void ImprimeElementoContainer(tElementoContainer * e){
    e->funcImprimeElemento(e->dado);
    printf("\n");
}
