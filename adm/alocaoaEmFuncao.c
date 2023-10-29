#include <stdio.h>
#include <stdlib.h>

void InicializaVetor(int *a, int tamanho, int valor)
{
    int i;
    for (i = 0; i < tamanho; i++)
        a[i] = valor;
}

void EscreveEmVetor(int valor, int n)
{
    int veti[n];
    for (int i = 0; i < n; i++)
        veti[i] = valor;
}

int *SomaVetores(int *a, int *b, int tamanho_dos_vetores)
{
    int i;
    int vet[tamanho_dos_vetores]; // Vamos testar com esse codigo errado
    int *resultado = vet;         // Descomentar essas linhas e comentar a debaixo
    // int *resultado = (int *)malloc(tamanho_dos_vetores * sizeof(int));

    for (i = 0; i < tamanho_dos_vetores; i++)
        resultado[i] = a[i] + b[i];

    return resultado;
}

int main()
{
    int n = 5;
    int *a = (int *)malloc(n * sizeof(int));
    int *b = (int *)malloc(n * sizeof(int));
    int *c;
    InicializaVetor(a, n, 1);
    InicializaVetor(b, n, 2);
    c = SomaVetores(a, b, n);
    EscreveEmVetor(11, 30);
    for (int i = 0; i < n; i++)
        printf("%d ", c[i]);
    printf("\n");

    free(a);
    free(b);
    // free(c);
    return 0;
}
