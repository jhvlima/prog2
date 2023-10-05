#ifndef _VETOR_H
#define _VETOR_H

typedef struct {
    int colunas;
    int linhas;
    int * valores;
} tMatriz;

//Cria uma matriz com a dimensao informada
tMatriz * CriaMatriz(int linhas, int colunas);

//Le uma matriz da entrada padrao
tMatriz * LeMatriz();

//Destroi uma matriz 
void FinalizaMatriz(tMatriz * m);

//Altera elemento da matriz
void AlteraElementoMatriz(tMatriz * m, int l, int c, int valor);

//Obtem elemento da matriz
int ObtemElementoMatriz(tMatriz * m, int l, int c);

//Obtem dimensoes da matriz
void ObtemDimensoesMatriz(tMatriz * m, int *linhas, int *colunas);

//Soma duas matrizes
void SomaMatriz(tMatriz * m1, tMatriz * m2, tMatriz * mSaida);

//Imprime as coordenadas do vetor dado na saida padrao
void ImprimirMatriz(tMatriz * m);

#endif
