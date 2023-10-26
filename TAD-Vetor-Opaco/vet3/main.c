#include <stdio.h>
#include "vetor.h"

int main() {

    tVetor* v1 = CriaVetor();
    LeVetor(v1);
    ImprimirVetor(v1);
    printf(" v1\n");
    tVetor* v2 = CriaVetor();
    LeVetor(v2);
    ImprimirVetor(v2);
    printf(" v2\n");
    tVetor* vResult;
    float eResult;

    float x = ObtemCoordVetor(v1, 1);  
    float y = ObtemCoordVetor(v1, 2);  
    AlteraCoordVetor(v1, 1, y);  
    AlteraCoordVetor(v1, 2, x);  
    ImprimirVetor(v1);
    printf(" v1 trocado\n");
    vResult = SomaVetor(v1, v2);
    ImprimirVetor(vResult);
    printf(" v1 trocado + v2\n");
    eResult = ProdutoEscalarVetor(vResult, v1);
    printf("%.2f produto escalar\n", eResult);    
    FinalizaVetor(v1);
    FinalizaVetor(v2);
    FinalizaVetor(vResult);

    return 0;
}
