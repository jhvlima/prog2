#include <stdio.h>

typedef int (*Funcptr)(int, int);

int soma(int a, int b) {
return a + b;
}

int main() {
Funcptr computa;
computa = soma;
int resultado = computa(2, 3);
printf("Resultado: %d\n", resultado);
return 0;
}