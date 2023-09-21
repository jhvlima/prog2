
#include <stdio.h>

void modificaValor(int *v){
    *v = *v * 10;
}

int main() {
    int x = 10;
    printf("X: %d\n", x);
    modificaValor(&x);
    printf("X: %d\n", x);
    return 0;
}