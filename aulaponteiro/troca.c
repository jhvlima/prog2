#include <stdio.h>

void troca(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int v1 = 10, v2 = 20;
    troca(&v1, &v2);
    printf("- v1: %d\n", v1);
    printf("- v2: %d\n", v2);
}
