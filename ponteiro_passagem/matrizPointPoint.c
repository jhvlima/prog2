#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void ImprimeMatriz(int m, int n, int mat[m][n]){
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			printf("%02d ", mat[i][j]);
		}
		printf("\n");
	}
	
}

void InicializaMatriz(int m, int n, int mat[m][n]){
	int a = 1;
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			mat[i][j] = a++;
		}
	}
	
}

int main() {
	int m,n;
	printf("Digite o numero de linhas e colunas da matriz\n");
	scanf("%d%d", &m, &n);
    int mat[m][n];
	
	//Inicializa e imprime a matriz original
	InicializaMatriz(m, n, mat);
	printf("Imprime matriz original\n");
	ImprimeMatriz(m, n, mat);

	//Varre matriz usando o ponteiro para vetor de n elementos
	printf("Imprime matriz usando ponteiro para n elementos\n");
	int (*pD)[n] = mat;
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			printf("%02d ", *(*(pD+i)+j));
			//printf("%02d ", pD[i][j]); //Troque por essa linha e veja que também funciona
		}
		printf("\n");
	}

	//Varre matriz usando o ponteiro para 1 elemento
	printf("Imprime matriz usando ponteiro 1 elemento\n");
	int *p1 = &(mat[0][0]);
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			printf("%02d ", *(p1+j+i*n));
			//printf("%02d ", p1[i][j]); //Troque por essa linha e veja que NAO funciona, pois nao eh ponteiro para ponteiro
		}
		printf("\n");
	}

	//Varre matriz sequencialmente com ponteiro para 1 elemento
	printf("Imprime matriz sequencialmente usando ponteiro 1 elemento\n");
	int *p2 = &mat[0][0];
	for(int i = 0; i < m*n; i++){
		printf("%02d ", *(p2++));
		if ((i+1)%n==0) printf("\n"); 
	}

    return 0;
}