#include <stdio.h>
#include "vetor.h"

int main() {

    tVetor v1 = LeVetor();
    ImprimirVetor(v1);
    printf(" v1\n");
    tVetor v2 = LeVetor();
    ImprimirVetor(v2);
    printf(" v2\n");
    tVetor vResult;
    float eResult;

    float x = ObtemCoordVetor(v1, 1);  
    float y = ObtemCoordVetor(v1, 2);  
    v1 = AlteraCoordVetor(v1, 1, y);  
    v1 = AlteraCoordVetor(v1, 2, x);  
    ImprimirVetor(v1);
    printf(" v1 trocado\n");
    vResult = SomaVetor(v1, v2);
    ImprimirVetor(vResult);
    printf(" v1 trocado + v2\n");
    eResult = ProdutoEscalarVetor(vResult, v1);
    printf("%.2f produto escalar\n", eResult);    

    return 0;
}
