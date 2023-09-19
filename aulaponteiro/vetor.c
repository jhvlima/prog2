#include <stdio.h>

int main(){
    float notas[10] = {1.2, 7.7, 4.9, 10, 6.5, 7.1, 8.2, 9.1, 8.9, 7.0};
    float *pont;
    pont = notas;
    printf("- notas = %f\n", *(pont+3));
    return 0;
}