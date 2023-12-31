#include <stdio.h>
#include <string.h>

typedef struct
{
	char nome[100];
} tTime;

tTime CriaTime(char nome[])
{
	tTime time;
	strcpy(time.nome, nome);
	return time;
}

void ImprimeTime(tTime *time)
{
	printf("%s", time->nome);
}

typedef struct
{
	char nome[100];
	tTime *time;
} tTorcedor;

tTorcedor CriaTorcedor(char nome[], tTime *time)
{
	tTorcedor torcedor;
	strcpy(torcedor.nome, nome);
	torcedor.time = time;
	return torcedor;
}

void ImprimeTorcedor(tTorcedor *torcedor)
{
	printf("%s torce para ", torcedor->nome);
	ImprimeTime(torcedor->time);
	printf("\n");
}

int main()
{
	int ti = 3;
	tTime times[ti];
	times[0] = CriaTime("Piracicaba");
	times[1] = CriaTime("Estrela");
	times[2] = CriaTime("Rio Branco");

	int to = 5;
	tTorcedor torcedores[to];
	torcedores[0] = CriaTorcedor("Chapolin", &times[0]);
	torcedores[1] = CriaTorcedor("Seu Madruga", &times[2]);
	torcedores[2] = CriaTorcedor("Chaves", &times[1]);
	torcedores[3] = CriaTorcedor("Chiquinha", &times[0]);
	torcedores[4] = CriaTorcedor("Kiko", &times[2]);

	printf("Imprime torcedores:\n");
	for (int i = 0; i < to; i++)
	{
		ImprimeTorcedor(&torcedores[i]);
	}

	printf("\n");
	printf("Imprime times:\n");
	for (int i = 0; i < ti; i++)
	{
		ImprimeTime(&times[i]);
		printf("\n");
	}
	return 0;
}