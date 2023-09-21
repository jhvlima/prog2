#include <stdio.h>

int modificaValor(int v){
    v = v * 10;
    return v;
}

int main() {
    int x = 10;
    printf("X: %d\n", modificaValor(x));
    printf("X: %d\n", x);
    return 0;
}