j#include <stdio.h>

#define cima 1
#define baixo 2
#define direita 3
#define esquerda 4

typedef struct
{
    int linha;
    int coluna;
} tCoordenada;

typedef struct
{
    int linhas;
    int colunas;
    int celula[25][25];
} tMapa;

typedef struct
{
    tMapa mapa;
    tCoordenada posicaoFinal;
    tCoordenada posicaoAtual;
    tOrdem prioridade;
    int gameOver;
} tJogo;

typedef struct 
{
    char primeiro;
    char segundo;
    char terceiro;
    char quarto;
}tOrdem;

tJogo LeEstadoDoJogo()
{
    tJogo jogo;
    jogo.mapa = InicializaMapa();
    jogo.posicaoAtual = InicializaPosicaoAtual();
    jogo.posicaoFinal = InicializaPosicaoFinal();
    jogo.prioridade = InicializaPrioridade();  
    jogo.gameOver = 0;
    return jogo;  
} 

tOrdem InicializaPrioridade()
{
    tOrdem prioridade;
    scanf("%*[^B-E]");
    scanf("%c", prioridade.primeiro);
    scanf("%c", prioridade.segundo);
    scanf("%c", prioridade.terceiro);
    scanf("%c", prioridade.quarto);
    return prioridade;
}

tCoordenada InicializaPosicaoFinal()
{
    tCoordenada posicaoDoFim;
    scanf("%d %d", &posicaoDoFim.linha, &posicaoDoFim.coluna);
    return posicaoDoFim;
}
tCoordenada InicializaPosicaoAtual()
{
    tCoordenada posicaoAtual;
    scanf("%d %d", &posicaoAtual.linha, &posicaoAtual.coluna);
    return posicaoAtual;
}

tMapa InicializaMapa()
{
    tMapa mapa;
    int qntLinhas, qntColunas, valor;
    scanf("%d %d", &qntLinhas, &qntColunas);
    for(int i = 0; i <= qntLinhas; i++)
    {
        for(int j = 0; j <= qntColunas; j++)
        {
            scanf("%d", &valor);
            mapa.celula[i][j] = valor;
        }
    }
    return mapa;
}

tJogo Movimenta(tJogo jogo)
{
    //
    movedirecaoprimeira(mapa, prioridade, posicaoAtual)
    {
        if(podemover(mapa, posicaoAtual, direcao))
        {
            atualizaCoord();
            return;
        }  
    }
    gameOver = 1;
    //
    
        if (PodefazerMovimento(jogo.posicaoAtual, jogo.mapa, jogo.prioridade))
    {
        jogo.posicaoAtual = MovimentaCoordenada(jogo.posicaoAtual, jogo.prioridade);
    }
    else
    {
        jogo.gameOver = 1;
    }
    return jogo;
}

int PodefazerMovimento(tCoordenada posicaoAtual, tMapa mapa, tOrdem prioridade)
{
    if (PodefazerMovimentoPrioridade(prioridade.primeiro, ))
    {
        /* code */
    }
    else if(PodefazerMovimento(prioridade.segundo))
    {
        /* code */
    }
    else if (PodefazerMovimento(prioridade.terceiro))
    {
        /* code */
    }
    else if (PodefazerMovimento(prioridade.quarto))
    {

    }
}

int PodefazerMovimentoPrioridade(char prioridade, tMapa mapa, tCoordenada posicaoAtual)
{

}
int TemMaisMovimento(tJogo jogo)
{
    if (ChegouAoFim() || NaoTemMovimento())
    {
        return 0;
    }
    else
    {
        return 1;
    } 
}

void JogaJogo(tJogo jogo)
{
    PrintaPosicao(jogo);
    while(TemMaisMovimento(jogo))
    {
        jogo = Movimenta(jogo);
        PrintaPosicao(jogo);
    }
}

void PrintaPosicao(tJogo jogo)
{
    printf("(%d,%d)", jogo.posicaoAtual.linha, jogo.posicaoAtual.coluna);
}

int main()
{
    tJogo jogo;
    jogo = LeEstadoDoJogo();
    JogaJogo(jogo);
    return 0;
}