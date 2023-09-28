#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "vetor.h"

tVetor LeVetor(){
    tVetor vet;
    vet.dimEspaco = 2;
    scanf("%*[ \n]");
    scanf("(%f,%f", &(vet.x), &(vet.y));
    if ( scanf(",%f)", &(vet.z)) == 1){
        vet.dimEspaco = 3;
    } else {
        scanf(")"); 
    }
    return vet;
}

tVetor AlteraCoordVetor(tVetor v, int coord, float valor){
    if (coord == 1){
        v.x = valor;
    } else if (coord == 2){
        v.y = valor;
    } else if (coord == 3 && v.dimEspaco > 2){
        v.z = valor;
    } else {
        printf("Nao existe no espaco de dim %d\n", v.dimEspaco);
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
    } else if (coord == 3 && v.dimEspaco > 2){
        valor = v.z;
    } else {
        printf("Nao existe no espaco de dim %d\n", v.dimEspaco);
        exit(1);
    }    
    return valor;
}

tVetor SomaVetor(tVetor v1, tVetor v2){
    tVetor vet;
    vet.dimEspaco = v1.dimEspaco;
    vet.x = v1.x + v2.x;
    vet.y = v1.y + v2.y;
    if (v1.dimEspaco>2){
        vet.z = v1.z + v2.z;
    }
    return vet;    
}

float ProdutoEscalarVetor(tVetor v1, tVetor v2){
    float raiz;
    if (v1.dimEspaco>2){
        raiz = sqrt(v1.x*v2.x + v1.y*v2.y + v1.z*v2.z);
    } else {
        raiz = sqrt(v1.x*v2.x + v1.y*v2.y);
    }
    return raiz;
}

void ImprimirVetor(tVetor v){
    if (v.dimEspaco>2){
        printf("(%.2f,%.2f,%.2f)", v.x, v.y, v.z);
    } else {
        printf("(%.2f,%.2f)", v.x, v.y);
    }
}