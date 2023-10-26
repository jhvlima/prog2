#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "vetor.h"

struct _tVetor{
    float x, y;
};

tVetor* CriaVetor(){
    tVetor* v = (tVetor*)malloc(sizeof(tVetor));
    return v;
}

void FinalizaVetor(tVetor* v){
    free(v);
}

void LeVetor(tVetor* v){
    scanf("%*[ \n]");
    scanf("(%f,%f)", &(v->x), &(v->y));
}

void AlteraCoordVetor(tVetor* v, int coord, float valor){
    if (coord == 1){
        v->x = valor;
    } else if (coord == 2){
        v->y = valor;
    } else {
        printf("Nao existe\n");
        exit(1);
    }
}

float ObtemCoordVetor(tVetor* v, int coord){
    float valor;
    if (coord == 1){
        valor = v->x;
    } else if (coord == 2){
        valor = v->y;
    } else {
        printf("Nao existe\n");
        exit(1);
    }    
    return valor;
}

tVetor* SomaVetor(tVetor* v1, tVetor* v2){
    tVetor* vet = CriaVetor();
    vet->x = v1->x + v2->x;
    vet->y = v1->y + v2->y;
    return vet;    
}

float ProdutoEscalarVetor(tVetor* v1, tVetor* v2){
    return sqrt(v1->x*v2->x + v1->y*v2->y);
}

void ImprimirVetor(tVetor* v){
    printf("(%.2f,%.2f)", v->x, v->y);
}