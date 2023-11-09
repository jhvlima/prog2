#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>

int CompararInteiros(const void *a, const void *b) {
    return *((int*)a) - *((int*)b);
}

int CompararDoubles(const void *a, const void *b) {
    return *((double*)a) > *((double*)b);    
}

int main() {
    int arrInt[ ] = {64, 34, 25, 12, 22, 11, 90};
    int nInt = sizeof(arrInt) / sizeof(arrInt[0]);
    BubbleSort(arrInt, nInt, sizeof(arrInt[0]), CompararInteiros);
    for(int i = 0; i < nInt; i++){
        printf("%d ", arrInt[i]);
    }
    printf("\n");

    double arrDouble[ ] = {64.0, 34.4, 34.02, 25.0, 12.0, 12.5, 22.0, 11.0, 90.0};
    int nDouble = sizeof(arrDouble) / sizeof(arrDouble[0]);
    BubbleSort(arrDouble, nDouble, sizeof(arrDouble[0]), CompararDoubles);
    for(int i = 0; i < nDouble; i++){
        printf("%.2lf ", arrDouble[i]);
    }
    printf("\n");

    return 0;
}
