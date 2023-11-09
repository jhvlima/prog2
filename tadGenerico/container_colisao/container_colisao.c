#include "container_colisao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct _tContainerColisao{
    int quantidadeElementos; 
	tElementoContainer**elementos;
};

tContainerColisao * CriaContainerColisao(){
	tContainerColisao * c = malloc(sizeof(tContainerColisao));
    c->quantidadeElementos = 0;
    c->elementos = NULL;
	return c;
}

void FinalizaContainerColisao(tContainerColisao * c){
    //Libera memoria de cada elemento do container
    for(int i = 0; i < c->quantidadeElementos; i++){
        FinalizaElementoContainer(c->elementos[i]);
    }
    //Libera o vetor de elementos
    if (c->elementos) free(c->elementos);
    free(c);    
}

void AdicionaElementoContainerColisao(  tContainerColisao * c, 
                                        void * elem, 
                                        FptrFinalizaElemento funcFinalizaElemento, 
                                        FptrColisaoElemento funcColisaoElemento,
                                        FptrTrataColisaoElemento funcTrataColisaoElemento,
                                        FptrImprimeElemento funcImprimeElemento){
    tElementoContainer * e = CriaElementoContainer( elem, 
                                                    funcFinalizaElemento, 
                                                    funcColisaoElemento, 
                                                    funcTrataColisaoElemento, 
                                                    funcImprimeElemento);

	(c->quantidadeElementos)++;
    c->elementos = realloc(c->elementos, c->quantidadeElementos * sizeof(tElementoContainer*));  
    c->elementos[c->quantidadeElementos-1] = e;
}

int VerificaColisaoContainerColisao(tContainerColisao * c, int x, int y){
    int teveColisao = 0;
    for(int i = 0; i < c->quantidadeElementos; i++){
        if (ColisaoElementoContainer(c->elementos[i], x, y)){
            TrataColisaoElementoContainer(c->elementos[i]);
            teveColisao++;
        }
    }
    return teveColisao;
}

void ListaElementosContainerColisao(tContainerColisao * c){
    for(int i = 0; i < c->quantidadeElementos; i++){
        ImprimeElementoContainer(c->elementos[i]);
    }    
}