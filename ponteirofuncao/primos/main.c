#include "primos.h"
#include <stdio.h>
#include <stdlib.h>

void Progresso(unsigned int valor, unsigned int total) { 
    printf("%.0lf%%\n", 100*(double)valor/total);
    printf("\033[H\033[J"); // Limpa o terminal   
}

int main() {
    unsigned int num;
    scanf("%u", &num);
    
    int qtd = QuantosPrimosAtehX(num, Progresso);
 
    printf("Qtd de primos ateh %d eh %d\n", num, qtd);
    
    return 0;
}
