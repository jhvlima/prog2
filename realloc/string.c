#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    size_t tamanho = 0;  // Tamanho atual da string
    char *string = NULL; // Inicialmente, a string é nula
                         //    char *string = (char *)malloc(1000); // Inicializa memoria com 100 bytes
    int caractere;

    while ((caractere = getchar()) != '\n' && caractere != EOF)
    {
        tamanho++; // Aumenta o tamanho da string

        // Realoca a memória para acomodar o novo caractere
        string = realloc(string, tamanho);

        if (string == NULL)
        {
            printf("Falha na alocação de memória.\n");
            exit(1);
        }

        // Adiciona o caractere à string
        string[tamanho - 1] = caractere;
    }

    // Adiciona o caractere nulo para terminar a string
    string = realloc(string, tamanho + 1);
    string[tamanho] = '\0';

    printf("Você digitou: %s\n", string);

    // Libera a memória alocada
    free(string);

    return 0;
}
