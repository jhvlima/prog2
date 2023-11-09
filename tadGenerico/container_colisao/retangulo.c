#include "retangulo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _tRetangulo{
    int id;
    int xInfEsq;
    int yInfEsq;
    int xSupDir;
    int ySupDir;
};

tRetangulo * CriaRetangulo(int id, int xInfEsq, int yInfEsq, int xSupDir, int ySupDir){
	tRetangulo * r = malloc(sizeof(tRetangulo));
    r->id = id;
    r->xInfEsq = xInfEsq;
    r->yInfEsq = yInfEsq;
    r->xSupDir = xSupDir;
    r->ySupDir = ySupDir;
	return r;
}

void FinalizaRetangulo(void * elem){
    tRetangulo * r = (tRetangulo *)elem;
    free(r);    
}

void ImprimeRetangulo(void * elem){
    tRetangulo * r = (tRetangulo *)elem;
    printf("Retangulo (%d,%d,%d,%d)", r->xInfEsq, r->yInfEsq, r->xSupDir, r->ySupDir);
}

int ColisaoRetangulo(void* elem, int x, int y){
    tRetangulo * r = (tRetangulo *)elem;
    return r->xInfEsq <= x && r->yInfEsq <= y &&  x <= r->xSupDir && y <= r->ySupDir;
}

void TratarColisaoRetangulo(void* elem){
    tRetangulo * r = (tRetangulo *)elem;
    printf("Elemento %d: ", r->id);
    ImprimeRetangulo(r);
    printf(" colidiu.\n");
}
