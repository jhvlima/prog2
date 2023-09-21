#include <stdio.h>
int main() {

int x = 10;
int *p1 = &x;
int **p2 = &p1;

printf("Conteudo em p1: %d\n", *p1);
printf("Conteudo em p2: %d\n", **p2);

return 0;
}