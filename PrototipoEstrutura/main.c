#include <stdio.h>
#include "empregado.h"

int main()
{
    int qtd;
    scanf("%d", &qtd);

    tEmpregado *empregados[qtd];
    for (int i = 0; i < qtd; i++)
    {
        empregados[i] = LeEmpregado();
        // Se for gerente
        if (EhGerenteEmpregado(empregados[i]))
        {
            // Artibui superior aos colaboradores
            int j = i - 1;
            while (j >= 0 && EhColaboradorEmpregado(empregados[j]))
            {
                AtribuiSuperiorEmpregado(empregados[j], empregados[i]);
                j--;
            }
        }
        // Se for diretor
        if (EhDiretorEmpregado(empregados[i]))
        {
            // Artibui superior aos gerentes
            for (int j = 0; j < i; j++)
            {
                if (EhGerenteEmpregado(empregados[j]))
                    AtribuiSuperiorEmpregado(empregados[j], empregados[i]);
            }
        }
    }

    for (int i = 0; i < qtd; i++)
    {
        ImprimirSuperioresEmpregado(empregados[i]);
    }

    for (int i = 0; i < qtd; i++)
    {
        FinalizaEmpregado(empregados[i]);
    }

    return 0;
}
