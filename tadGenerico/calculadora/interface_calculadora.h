#ifndef _INTERFACE_CALCULADORA_H
#define _INTERFACE_CALCULADORA_H

typedef int (*FptrOperacao)(int, int);

typedef struct _tCalculadora tCalculadora;

//Cria uma Calculadora progamavel
tCalculadora * CriaCalculadora();

//Finaliza uma Calculadora progamavel
void FinalizaCalculadora(tCalculadora * calc);

//Adiciona operacao calculadora
void AdicionaOperacaoCalculadora(tCalculadora * calc, char nome[], FptrOperacao operacao);

//Entra no menu da caculadora para realizar operacoes
void ExecutaCalculadora(tCalculadora * calc);

#endif
