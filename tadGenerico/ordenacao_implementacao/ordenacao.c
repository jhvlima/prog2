#include "ordenacao.h"
#include <stdio.h>
#include <string.h>

void BubbleSort(void *arr, int tamArr, int tamElemArrInBytes, int (*Comparar)(const void *, const void *))
{
	int i, j;
	// qtd de memoria necessaria para um elemento de arr, entao da para armazenar um item
	char temp[tamElemArrInBytes];
	for (i = 0; i < tamArr - 1; i++)
	{
		for (j = 0; j < tamArr - i - 1; j++)
		{
			// Comparar arr[j] com arr[j+1], porem [j] nao funciona pois o ponteiro void nao sabe o qto pular
			// Usamos o tamElemArrInBytes para saber o qto pular a partir de arr
			if (Comparar(arr + tamElemArrInBytes * j, arr + tamElemArrInBytes * (j + 1)) > 0)
			{
				// A funcao memcpy copia uma qtd de memoria de um lugar para o outro
				// equivalente a temp = arr[j];
				memcpy(temp, arr + tamElemArrInBytes * j, tamElemArrInBytes);
				// equivalente a arr[j] = arr[j+1];
				memcpy(arr + tamElemArrInBytes * j, arr + tamElemArrInBytes * (j + 1), tamElemArrInBytes);
				// equivalente a arr[j+1] = temp;
				memcpy(arr + tamElemArrInBytes * (j + 1), temp, tamElemArrInBytes);
			}
		}
	}
}
