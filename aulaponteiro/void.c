#include <stdio.h>

int main() {

    void *pp;
    int p2 = 10;

    pp = &p2;
    printf("Conteudo: %d", *((int*)pp));

    return 0;
}

