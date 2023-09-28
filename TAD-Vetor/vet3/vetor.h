#ifndef _VETOR_H
#define _VETOR_H

typedef struct {
    int dimEspaco;
    float x, y, z;
} tVetor;

//Le e retorna um vetor da entrada padrao
tVetor LeVetor();

//Altera uma coordenada (coord 1 indica a primeir, 2 a segunda, etc) de um vetor com o valor dado
tVetor AlteraCoordVetor(tVetor v, int coord, float valor);

//Retorna o valor da coordenada (coord 1 indica a primeir, 2 a segunda, etc) de um vetor
float ObtemCoordVetor(tVetor v, int coord);

//Soma dois vetores validos e retorna o resultado em um vetor
tVetor SomaVetor(tVetor v1, tVetor v2);

//Faz o produto escalar entre dois vetores validos e retorna o resultado escalar
float ProdutoEscalarVetor(tVetor v1, tVetor v2);

//Imprime as coordenadas do vetor dado na saida padrao
void ImprimirVetor(tVetor v);

#endif
