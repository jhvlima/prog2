#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "vetor.h"

tVetor LeVetor(){
    tVetor vet;
    scanf("%*[ \n]");
    scanf("(%f,%f)", &(vet.x), &(vet.y));
    return vet;
}

tVetor AlteraCoordVetor(tVetor v, int coord, float valor){
    if (coord == 1){
        v.x = valor;
    } else if (coord == 2){
        v.y = valor;
    } else {
        printf("Nao existe\n");
        exit(1);
    }
    return v;
}

float ObtemCoordVetor(tVetor v, int coord){
    float valor;
    if (coord == 1){
        valor = v.x;
    } else if (coord == 2){
        valor = v.y;
    } else {
        printf("Nao existe\n");
        exit(1);
    }    
    return valor;
}

tVetor SomaVetor(tVetor v1, tVetor v2){
    tVetor vet;
    vet.x = v1.x + v2.x;
    vet.y = v1.y + v2.y;
    return vet;    
}

float ProdutoEscalarVetor(tVetor v1, tVetor v2){
    return sqrt(v1.x*v2.x + v1.y*v2.y);
}

void ImprimirVetor(tVetor v){
    printf("(%.2f,%.2f)", v.x, v.y);
}