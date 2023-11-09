#include "interface_calculadora.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _tCalculadora{
	int numOperacoes;
	FptrOperacao * operacoes; 
	char **nomeOperacao;
};

tCalculadora* CriaCalculadora(){
	tCalculadora * calc = malloc(sizeof(tCalculadora));
    calc->operacoes = NULL; 
	calc->numOperacoes = 0;
    calc->nomeOperacao = NULL; 
	return calc;
}

void FinalizaCalculadora(tCalculadora * calc){
    for(int i = 0; i < calc->numOperacoes; i++){
        free(calc->nomeOperacao[i]);
    }
    if(calc->nomeOperacao) free(calc->nomeOperacao);
    if(calc->operacoes) free(calc->operacoes);
    free(calc);
}

void AdicionaOperacaoCalculadora(tCalculadora * calc, char nome[], FptrOperacao operacao){
	(calc->numOperacoes)++;
    calc->operacoes = realloc(calc->operacoes, calc->numOperacoes * sizeof(FptrOperacao)); 
	calc->operacoes[calc->numOperacoes-1] = operacao;
    calc->nomeOperacao = realloc(calc->nomeOperacao, calc->numOperacoes * sizeof(char *)); 
    calc->nomeOperacao[calc->numOperacoes-1] = malloc(strlen(nome)+1 * sizeof(char)); 
	strcpy(calc->nomeOperacao[calc->numOperacoes-1], nome);
}

void ImprimeMenuCalculadora(tCalculadora * calc){
	int i;
	printf("Escolha uma das operacoes abaixo:\n");
	for(i = 0; i < calc->numOperacoes; i++){
		printf("%d - %s\n", i, calc->nomeOperacao[i]);
	}
	printf("%d - Finalizar\n", i);
}

void ExecutaCalculadora(tCalculadora * calc){
	int opcao, num1, num2, rtn;
	while(1){
		//Imprime menu
		ImprimeMenuCalculadora(calc);
		//Le opcao digitada
		rtn = scanf("%d", &opcao);
		//Verifica se eh opcao para finalizar 
		if (opcao == calc->numOperacoes) break;
		//Verifica se opcao eh valida
		if (rtn < 1 || opcao < 0 || opcao > calc->numOperacoes){ 
			scanf("%*[^\n]"); //Limpa o buffer se nao for valido
			printf("Opcao Invalida!\n");
			continue;
		}
		//Pede os inteiros
		printf("Digite dois numeros inteiros:");
		rtn = scanf("%d%d", &num1, &num2);
		//Verifica se o formato eh valido
		if (rtn < 2){
			scanf("%*[^\n]"); //Limpa o buffer se nao for valido
			printf("Formato invalido!\n");
			continue;
		}
		//Realiza operacao e da o resultado
		int resultado = calc->operacoes[opcao](num1, num2);
		printf("Resultado de %s %d e %d = %d\n", calc->nomeOperacao[opcao], num1, num2, resultado);
	}
}