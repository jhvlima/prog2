#include "sorteador.h"
#include "pessoa.h"
#include <stdio.h>
#include <stdlib.h>

#define NUM_PESSOAS 5
#define NUM_INTS 10

int main() {
	tSorteador * sort = CriaSorteador(1);

    //Cria uma lista de pessoas
    tPessoa * pessoas[NUM_PESSOAS];
    pessoas[0] = CriaPessoa("Fulano", 33);
    pessoas[1] = CriaPessoa("Ciclano", 43);
    pessoas[2] = CriaPessoa("Beltrano", 20);
    pessoas[3] = CriaPessoa("Geronimo", 25);
    pessoas[4] = CriaPessoa("Anonimo", 50);

    //Cadastra pessoas para sorteio
    for(int i = 0; i < NUM_PESSOAS; i++){
        AdicionaElementoSorteador(sort, pessoas[i]);
    }

    //Sorteia enquanto tiver pessoas para sortear e imprime
    tPessoa *pessoa;
    while(TemElementosSorteador(sort)){
        pessoa = SorteiaElementoSorteador(sort);
        ImprimePessoa(pessoa);
    }

    int numeros[NUM_INTS] = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000};
    //Cadastra pessoas para sorteio
    for(int i = 0; i < NUM_INTS; i++){
        AdicionaElementoSorteador(sort, &(numeros[i]));
    }

    //Sorteia enquanto tiver pessoas para sortear e imprime
    while(TemElementosSorteador(sort)){
        int * num = SorteiaElementoSorteador(sort);
        printf("%d ", *num);
    }
    printf("\n");

    //Libera memoria
    for(int i = 0; i < NUM_PESSOAS; i++){
        FinalizaPessoa(pessoas[i]);
    }
    FinalizaSorteador(sort);
	
    return 0;
}