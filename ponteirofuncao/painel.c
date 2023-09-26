#include <stdio.h>
#include <stdlib.h>
#define TAM_PAINEL_VERT 5
#define TAM_PAINEL_HORI 100
#define ESPACO 2

typedef void (*FptrDesenha)(char painel[TAM_PAINEL_VERT][TAM_PAINEL_HORI], int pos);

void ImprimePainel(char painel[TAM_PAINEL_VERT][TAM_PAINEL_HORI]) { 
    printf("\033[H\033[J"); // Limpa o terminal   
    for(int i = 0; i < TAM_PAINEL_VERT; i++){
        for(int j = 0; j < TAM_PAINEL_HORI; j++){
            printf("%c", painel[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void ResetaPainel(char painel[TAM_PAINEL_VERT][TAM_PAINEL_HORI]) { 
    for(int i = 0; i < TAM_PAINEL_VERT; i++){
        for(int j = 0; j < TAM_PAINEL_HORI; j++){
            painel[i][j] = ' ';
        }
    }
}

void CopiaLetraPainel(char painel[TAM_PAINEL_VERT][TAM_PAINEL_HORI], char letra[TAM_PAINEL_VERT][TAM_PAINEL_VERT], int pos) { 
    for(int i = 0; i < TAM_PAINEL_VERT; i++){
        for(int j = 0; j < TAM_PAINEL_VERT; j++){
            painel[i][pos+j] = letra[i][j];
        }
    }
}

void DesenhaC(char painel[TAM_PAINEL_VERT][TAM_PAINEL_HORI], int pos){ 
    char letra[TAM_PAINEL_VERT][TAM_PAINEL_VERT] =  {   "XXXXX",
                                                        "X    ",
                                                        "X    ",
                                                        "X    ",
                                                        "XXXXX"};
    
    CopiaLetraPainel(painel, letra, pos);
}

void DesenhaA(char painel[TAM_PAINEL_VERT][TAM_PAINEL_HORI], int pos){ 
    char letra[TAM_PAINEL_VERT][TAM_PAINEL_VERT] =  {   "XXXXX",
                                                        "X   X",
                                                        "XXXXX",
                                                        "X   X",
                                                        "X   X"};
    
    CopiaLetraPainel(painel, letra, pos);
}

void DesenhaS(char painel[TAM_PAINEL_VERT][TAM_PAINEL_HORI], int pos){ 
    char letra[TAM_PAINEL_VERT][TAM_PAINEL_VERT] =  {   "XXXXX",
                                                        "X    ",
                                                        "XXXXX",
                                                        "    X",
                                                        "XXXXX"};
    
    CopiaLetraPainel(painel, letra, pos);
}

void LimpaDesenho(char painel[TAM_PAINEL_VERT][TAM_PAINEL_HORI], int pos) { 
    ResetaPainel(painel);
}

void ConfiguraFuncoes(FptrDesenha * FptrFuncoesDesenho) { 
    FptrFuncoesDesenho['c'] = DesenhaC;
    FptrFuncoesDesenho['C'] = DesenhaC;
    FptrFuncoesDesenho['a'] = DesenhaA;
    FptrFuncoesDesenho['A'] = DesenhaA;
    FptrFuncoesDesenho['s'] = DesenhaS;
    FptrFuncoesDesenho['S'] = DesenhaS;
    FptrFuncoesDesenho[' '] = LimpaDesenho;
}


int main() {
    char painel[TAM_PAINEL_VERT][TAM_PAINEL_HORI];
    FptrDesenha FptrFuncoesDesenho[256] = {NULL}; //inicializa todos elementos com 0
    ResetaPainel(painel);
    ConfiguraFuncoes(FptrFuncoesDesenho);

    int i = 0;
    while (1){
        char tecla;
        scanf("%c", &tecla);
        scanf("%*[^\n]");
        scanf("%*c");
        
        if ( FptrFuncoesDesenho[tecla] != NULL ){
            FptrFuncoesDesenho[tecla](painel, i*(TAM_PAINEL_VERT + ESPACO));
            ImprimePainel(painel);
            if ( tecla == ' ')
                i = 0;
            else   
                i++;
        }
    }
        
    return 0;
}
