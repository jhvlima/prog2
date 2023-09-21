#include <stdio.h>

void Trocavalor(int* vet[], int i, int j){
    int* aux;
    aux = vet[j];
    vet[j] = vet[i];
    vet[i] = aux;
}

int EhMenorAqB(int* a, int* b){
    return *a < *b;
}

int AcharMenorEntreAeB(int *vet[], int a, int b){
	int i, idx; 
	int* menor;

	menor = vet[a];
	idx = a;
	for(i = a+1; i <= b; i++){
		if ( EhMenorAqB(vet[i], menor) ){ 
			menor = vet[i];
			idx = i;
		}
	}
	return idx;
}

void OrdeneVetPointCrescente(int *vet[], int qtd){
	int i, idxMenor;
	for(i = 0; i < qtd-1; i++){
		idxMenor = AcharMenorEntreAeB(vet, i+1, qtd-1);
		if ( EhMenorAqB(vet[idxMenor], vet[i]) ){
			Trocavalor (vet, idxMenor, i);
		}
	}
}

//Inicializa em ordem decrescente
void InicializaVet(int vet[], int qtd){
	for(int i = 0; i < qtd; i++){
		vet[i] = qtd - i;
	}
}

//Inicializa com pointeiros para cada elemento
void InicializaVetPoint(int vet[], int *vetPoint[], int qtd){
	for(int i = 0; i < qtd; i++){
		vetPoint[i] = &(vet[i]);
	}
}

int main() {
	int n;
	scanf("%d", &n);
    int x[n];	
	int *xPont[n];
	InicializaVet(x, n);
	InicializaVetPoint(x, xPont, n);
    	
	OrdeneVetPointCrescente(xPont, n);
	
	//Imprime vetor de ponteiros
	printf("Ponteiros: ");
	for(int i=0; i<n; i++)
		printf("%d ", *(xPont[i]));
	printf("\n");
	
	//Imprime vetor de original
	printf("Originais: ");
	for(int i=0; i<n; i++)
		printf("%d ", x[i]);
	printf("\n");
    
    return 0;
}
