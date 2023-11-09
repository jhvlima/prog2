#ifndef _PONTO_H
#define _PONTO_H

typedef struct _tPonto tPonto;

//Cria um ponto
tPonto * CriaPonto(int id, int x, int y);

//Finaliza um ponto
void FinalizaPonto(void * p);

//Imprime um ponto
void ImprimePonto(void * p);

//Verifica colisao do ponto com a posicao informada
int ColisaoPonto(void* elem, int x, int y);

//Trata uma colisao com o ponto
void TratarColisaoPonto(void* elem);

#endif
