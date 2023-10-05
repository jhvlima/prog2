#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    char *nome = (char *)malloc(100 * sizeof(char));
    strcpy(nome, "Anakin");
    printf("- Nome salvo: %s\n", nome);

    FILE *f = fopen("saida.txt", "w");
    fprintf(f, "%s", nome);

    return 0;
}
