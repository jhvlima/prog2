#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void ImprimeMatriz(int m, int n, int mat[m][n])
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%02d ", mat[i][j]);
        }
        printf("\n");
    }
}

void InicializaMatriz(int m, int n, int mat[m][n])
{
    int a = 1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mat[i][j] = a++;
        }
    }
}

//int  a[10000][10000]; //global
int main()
{
    //int  a[10000][10000]; //stack
    int m, n;
    //int *b = malloc(100000*100000*sizeof(int)); //heap
    printf("Digite o numero de linhas e colunas da matriz\n");
    scanf("%d%d", &m, &n);
    int(*mat)[n] = malloc(m * n * sizeof(int)); // heap
    // Inicializa e imprime a matriz original
    InicializaMatriz(m, n, mat);
    ImprimeMatriz(m, n, mat);
    free(mat);
    return 0;
}