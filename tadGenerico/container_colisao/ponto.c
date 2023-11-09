#include "ponto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _tPonto{
    int id;
    int x; 
	int y;
};

tPonto * CriaPonto(int id, int x, int y){
	tPonto * p = malloc(sizeof(tPonto));
    p->id = id;
    p->x = x;
    p->y = y;
	return p;
}

void FinalizaPonto(void * elem){
    tPonto * p = (tPonto *)elem;
    free(p);    
}

void ImprimePonto(void * elem){
    tPonto * p = (tPonto *)elem;
    printf("Ponto (%d,%d)", p->x, p->y);
}

int ColisaoPonto(void* elem, int x, int y){
    tPonto * p = (tPonto *)elem;
    return p->x == x && p->y == y;
}

void TratarColisaoPonto(void* elem){
    tPonto * p = (tPonto *)elem;
    printf("Elemento %d: ", p->id);
    ImprimePonto(p);
    printf(" colidiu.\n");
}
