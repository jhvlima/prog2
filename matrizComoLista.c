
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void ImprimeMatriz(int m, int n, int **mat)
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

void InicializaMatriz(int m, int n, int **mat)
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

int **CriaMatriz(int m, int n)
{
    int **mat = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++)
    {
        mat[i] = (int *)malloc(n * sizeof(int));
    }
    return mat;
}

void DestroiMatriz(int m, int n, int **mat)
{
    for (int i = 0; i < m; i++)
    {
        free(mat[i]);
    }
    free(mat);
}

int main()
{
    int m, n;
    printf("Digite o numero de linhas e colunas da matriz\n");
    scanf("%d%d", &m, &n);
    int **mat = CriaMatriz(m, n);
    // Inicializa e imprime a matriz original
    InicializaMatriz(m, n, mat);
    // printf("valor %d\n", mat[0][n]);
    ImprimeMatriz(m, n, mat);
    DestroiMatriz(m, n, mat);
    printf("%d", mat[0][3]);
    return 0;
}
