#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "vetor.h"

struct _tVetor{
    int dimEspaco;
    float * valorCoord;
};

tVetor* CriaVetor(){
    tVetor* v = (tVetor*)malloc(sizeof(tVetor));
    v->dimEspaco = 0;
    v->valorCoord = NULL;
    return v;
}

void AlteraDimVetor(tVetor* v, int dim){
    v->dimEspaco = dim;
    v->valorCoord = (float*) realloc(v->valorCoord, (dim)*sizeof(float));
}

void FinalizaVetor(tVetor* v){
    if (v->valorCoord != NULL) free(v->valorCoord);
    free(v);
}

void LeVetor(tVetor* v){
    int i = 0;
    scanf("%*[ \n]");
    AlteraDimVetor(v, 2);
    scanf("(%f", &(v->valorCoord[i++]));
    while(scanf(",%f", &(v->valorCoord[i++])) == 1){
        v->dimEspaco++;
        AlteraDimVetor(v, v->dimEspaco);
    }
    scanf(")"); 
    //Corrige para ficar com o numero certo de memoria p dimensao
    AlteraDimVetor(v, v->dimEspaco-1);
}

void AlteraCoordVetor(tVetor* v, int coord, float valor){
    if (coord <= v->dimEspaco){
        v->valorCoord[coord-1] = valor;
    } else {
        printf("Coord %d nao existe no espaco de dim %d\n", coord, v->dimEspaco);
        exit(1);
    }
}

float ObtemCoordVetor(tVetor* v, int coord){
    float valor;
    if (coord <= v->dimEspaco){
        valor = v->valorCoord[coord-1];
    } else {
        printf("Coord %d nao existe no espaco de dim %d\n", coord, v->dimEspaco);
        exit(1);
    }
    return valor;
}

tVetor* SomaVetor(tVetor* v1, tVetor* v2){
    tVetor* vet = CriaVetor();
    AlteraDimVetor(vet, v1->dimEspaco);
    if (v1->dimEspaco == v2->dimEspaco){
        for(int i = 0; i < v1->dimEspaco; i++)
            vet->valorCoord[i] = v1->valorCoord[i]+v2->valorCoord[i];
    } else {
        printf("v1 coord %d eh diferente v2 coord %d\n", v1->dimEspaco, v2->dimEspaco);
        exit(1);
    }
    return vet;    
}

float ProdutoEscalarVetor(tVetor* v1, tVetor* v2){
    float soma = 0.0;
    if (v1->dimEspaco == v2->dimEspaco){
        for(int i = 0; i < v1->dimEspaco; i++)
            soma += v1->valorCoord[i]*v2->valorCoord[i];
    } else {
        printf("v1 coord %d eh diferente v2 coord %d\n", v1->dimEspaco, v2->dimEspaco);
        exit(1);
    }
    return sqrt(soma);
}

void ImprimirVetor(tVetor* v){
    int i;
    printf("(");
    for(i = 0; i < v->dimEspaco-1; i++)
        printf("%.2f,", v->valorCoord[i]);
    printf("%.2f)", v->valorCoord[i]);
}