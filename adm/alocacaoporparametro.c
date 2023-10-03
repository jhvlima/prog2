#include <stdlib.h>
#include <stdio.h>

void AlocaVetor(int tamanho, int valor, int **vetRetornado)
{
    *vetRetornado = malloc(tamanho * sizeof(int));
    for (int i = 0; i < tamanho; i++)
        (*vetRetornado)[i] = valor;
}

int main()
{
    int n = 3, *vet;
    AlocaVetor(n, 22, &vet);
    for (int i = 0; i < n; i++)
        printf("%d ", vet[i]);
    printf("\n");
    free(vet);
    return 0;
}
