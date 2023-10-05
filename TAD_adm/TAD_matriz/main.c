#include <stdio.h>
#include "matriz.h"

int main() {

    printf("M1\n");
    tMatriz * m1 = LeMatriz();
    ImprimirMatriz(m1);
    
    printf("M2\n");
    tMatriz * m2 = LeMatriz();
    ImprimirMatriz(m2);

    int linhas, colunas;
    ObtemDimensoesMatriz(m1, &linhas, &colunas);
    tMatriz * mResultado = CriaMatriz(linhas, colunas);
    SomaMatriz(m1, m2, mResultado);
    
    printf("Resultado\n");
    ImprimirMatriz(mResultado);
    
    FinalizaMatriz(m1);
    FinalizaMatriz(m2);
    FinalizaMatriz(mResultado);

    return 0;
}
