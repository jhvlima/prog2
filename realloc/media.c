#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int *LeInteiros(int *tamanho)
{
    *tamanho = 0;      // Tamanho atual do vetor
    int *vetor = NULL; // Inicialmente, o vetor é nulo
    int valor;

    while (scanf("%d", &valor) == 1 && valor >= 0)
    {
        (*tamanho)++; // Aumenta o tamanho da string

        // Realoca a memória para acomodar o novo caractere
        vetor = realloc(vetor, *tamanho * sizeof(int));

        if (vetor == NULL)
        {
            printf("Falha na alocação de memória.\n");
            exit(1);
        }

        // Adiciona o caractere à string
        vetor[*tamanho - 1] = valor;
    }

    return vetor;
}

void ImprimeVetor(int tamanho, int vetor[tamanho])
{
    if (tamanho == 0)
    {
        printf("[]\n");
        return;
    }

    printf("[%d", vetor[0]);
    for (int i = 1; i < tamanho; i++)
    {
        printf(",%d", vetor[i]);
    }
    printf("]\n");
}

float CalculaMediaVetor(int tamanho, int vetor[tamanho])
{
    float soma = 0;
    for (int i = 0; i < tamanho; i++)
    {
        soma += vetor[i];
    }
    return soma / tamanho;
}

float CalculaDesvioPadraoVetor(int tamanho, int vetor[tamanho])
{
    float soma = 0;
    float media = CalculaMediaVetor(tamanho, vetor); // Imprime numeros lidos
    for (int i = 0; i < tamanho; i++)
    {
        soma = pow(media - vetor[i],2);
    }
    return sqrt(soma)/tamanho;
    
}

int main()
{
    int *vetor;
    int tamanho;

    vetor = LeInteiros(&tamanho); // Le inteiros para um vetor

    ImprimeVetor(tamanho, vetor); // Imprime numeros lidos

    float media = CalculaMediaVetor(tamanho, vetor); // Imprime numeros lidos
    printf("media: %.2f\n", media);

    float desvio = CalculaDesvioPadraoVetor(tamanho, vetor); // Imprime numeros lidos
    printf("desvio: %.2f\n", desvio);
    free(vetor); // Libera vetor

    return 0;
}