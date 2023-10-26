#ifndef _VETOR_H
#define _VETOR_H

typedef struct _tVetor tVetor; 

//Cria valido com valores indefinidos
//Retorna um vetor valido criado ou NULL em caso de falha
tVetor* CriaVetor();

//Destroi um vetor valido
void FinalizaVetor(tVetor* v);

//Le dados da entrada padrao para um vetor valido
void LeVetor(tVetor* v);

//Altera uma coordenada (coord 1 indica a primeir, 2 a segunda, etc) de um vetor com o valor dado
void AlteraCoordVetor(tVetor* v, int coord, float valor);

//Retorna o valor da coordenada (coord 1 indica a primeir, 2 a segunda, etc) de um vetor
float ObtemCoordVetor(tVetor* v, int coord);

//Soma dois vetores validos e cria um terceiro vetor valido para retornar o resultado
tVetor* SomaVetor(tVetor* v1, tVetor* v2);

//Faz o produto escalar entre dois vetores validos e retorna o resultado escalar
float ProdutoEscalarVetor(tVetor* v1, tVetor* v2);

//Imprime as coordenadas do vetor dado na saida padrao
void ImprimirVetor(tVetor* v);

#endif
