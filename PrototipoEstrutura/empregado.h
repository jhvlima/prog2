#ifndef _EMPREGADO_H
#define _EMPREGADO_H

typedef struct _tEmpregado tEmpregado; 

//Le um empregado da entrada padrao e retorna um empregado valido
tEmpregado* LeEmpregado();

//Destroi um vetor valido
void FinalizaEmpregado(tEmpregado* e);

//Verifica se eh colaborador
int EhColaboradorEmpregado(tEmpregado* e);

//Verifica se eh gerente
int EhGerenteEmpregado(tEmpregado* e);

//Verifica se eh diretor
int EhDiretorEmpregado(tEmpregado* e);

//Atribui um superior ao empregado
void AtribuiSuperiorEmpregado(tEmpregado* e, tEmpregado* sup);

//Imprime empregado
void ImprimirEmpregado(tEmpregado* e);

//Imprime superiores empregado
void ImprimirSuperioresEmpregado(tEmpregado* e);

#endif
