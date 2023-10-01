#include <stdio.h>

int main()
{
    int nota, *pNota;
    nota = 10;
    pNota = &nota;
    printf("- Conteúdo apontado por pNota: %d\n", *pNota);
    *pNota = 8;
    printf("- Valor de nota: %d\n", nota);
}