#ifndef _SORTEADOR_H
#define _SORTEADOR_H

typedef struct _tSorteador tSorteador;

// Cria um sorteador de elementos
tSorteador *CriaSorteador(int usarSemente);

// Finaliza um sorteador
void FinalizaSorteador(tSorteador *sort);

// Adiciona elemento para ser sorteado
void AdicionaElementoSorteador(tSorteador *sort, void *elem);

// Sorteia um elemento e retira dos elementos a serem sorteados
void *SorteiaElementoSorteador(tSorteador *sort);

// Tem elementos
int TemElementosSorteador(tSorteador *sort);

#endif
