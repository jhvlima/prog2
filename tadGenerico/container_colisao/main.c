#include "container_colisao.h"
#include "ponto.h"
#include "retangulo.h"
#include <stdio.h>
#include <stdlib.h>

#define NUM_PESSOAS 5
#define NUM_INTS 10

void ImprimeMenu(){
    printf("\t0 - Cadastra Ponto\n");
    printf("\t1 - Cadastra Retangulo\n");
    printf("\t2 - Lista elementos do Container\n");
    printf("\t3 - Verifica colisao com elementos do Container\n");
    printf("\t4 - Sair\n");
}

int CadastraPonto(tContainerColisao * container, int id){
    int x, y;
    tPonto * p;
    printf("Digite uma posicao x y:\n");
    if (scanf("%d%d", &x, &y) == 2){
        p = CriaPonto(id++, x, y);
        AdicionaElementoContainerColisao(container, p, FinalizaPonto, ColisaoPonto, TratarColisaoPonto, ImprimePonto);
    } else {
        printf("Formato invalido!\n");
        scanf("%*[^\n]");
    }
    return id;
}

int CadastraRetangulo(tContainerColisao * container, int id){
    int xInfEsq, yInfEsq, xSupDir, ySupDir;
    tRetangulo * r;
    printf("Digite o x e o y do canto inferior esquerdo seguidos do x e do y do canto superior direito:\n");
    if (scanf("%d%d%d%d", &xInfEsq, &yInfEsq, &xSupDir, &ySupDir) == 4){
        r = CriaRetangulo(id++, xInfEsq, yInfEsq, xSupDir, ySupDir);
        AdicionaElementoContainerColisao(container, r, FinalizaRetangulo, ColisaoRetangulo, TratarColisaoRetangulo, ImprimeRetangulo);
    } else {
        printf("Formato invalido!\n");
        scanf("%*[^\n]");
    }
    return id;
}

void VerificaColisao(tContainerColisao * container){
    int x, y;
    printf("Digite um posicao x e y:\n");
    if (scanf("%d%d", &x, &y) == 2){
        printf("Verifica colisao com %d,%d:\n", x, y);
        int teveColisao = VerificaColisaoContainerColisao(container, x, y);
        if (!teveColisao) printf("Nao teve colisao em %d,%d!\n", x, y);
    } else {
        printf("Formato invalido!\n");
        scanf("%*[^\n]");
    }
}

int main() {
	tContainerColisao * container = CriaContainerColisao();
    int i = 0;

    //Imprime o menu e realiza operacoes disponiveis
    while(1){
        int op;
        ImprimeMenu();
        if (scanf("%d", &op) == 1){
            if(op == 0){
                i = CadastraPonto(container, i);
            } else if (op == 1){
                i = CadastraRetangulo(container, i);
            } else if (op == 2){
                ListaElementosContainerColisao(container);
            } else if (op == 3){
                VerificaColisao(container);
            } else if (op == 4){
                break;
            }
        } else {
            printf("Formato invalido!\n");
            scanf("%*[^\n]");
        }
    }

    //Libera memoria
    FinalizaContainerColisao(container);
	
    return 0;
}