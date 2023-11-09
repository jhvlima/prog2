#include "interface_calculadora.h"
#include <stdio.h>
#include <stdlib.h>

int soma(int num1, int num2)
{
	return num1 + num2;
}

int multiplica(int num1, int num2)
{
	return num1 * num2;
}

int main()
{

	tCalculadora *calc = CriaCalculadora();

	AdicionaOperacaoCalculadora(calc, "Soma", soma);

	AdicionaOperacaoCalculadora(calc, "Multiplica", multiplica);

	ExecutaCalculadora(calc);

	FinalizaCalculadora(calc);

	return 0;
}