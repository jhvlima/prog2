#include <stdio.h>

int soma(int a, int b) {
return a + b;
}

int main() {
int (*PonteiroFuncao)(int, int);
PonteiroFuncao = soma;
int resultado = PonteiroFuncao(2, 3);
printf("Resultado: %d\n", resultado);
return 0;
}