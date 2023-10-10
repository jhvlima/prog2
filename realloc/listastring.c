#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *LeString()
{
    size_t tamanho = 0;  // Tamanho atual da string
    char *string = NULL; // Inicialmente, a string é nula
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

    return string;
}

void ImprimeListaString(int tamanhoLista, char **listaString)
{
    for (int i = tamanhoLista - 1; i >= 0; i--)
    {
        printf("item %d: %s\n", i, listaString[i]);
    }
}

void LiberaListaString(int tamanhoLista, char **listaString)
{
    for (int i = 0; i < tamanhoLista; i++)
    {
        free(listaString[i]);
    }
    free(listaString);
}

int main()
{
    char **listaString = NULL;
    int tamanhoLista = 0;
    char *string;

    string = LeString();
    while (strcmp(string, "fim"))
    { // Le strings enquanto nao digitar fim
        tamanhoLista++;
        // Atualiza tamanho da memoria da lista de strings
        listaString = (char **)realloc(listaString, tamanhoLista * sizeof(char *));
        listaString[tamanhoLista - 1] = string;

        string = LeString();
    }

    ImprimeListaString(tamanhoLista, listaString); // Imprime lista de strings

    free(string);                                 // Libera a string fim
    LiberaListaString(tamanhoLista, listaString); // Libera a lista de strings

    return 0;
}