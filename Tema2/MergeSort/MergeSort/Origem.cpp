#include<stdio.h>
#include<stdlib.h>
#include <time.h>

#define TAMANHOVETOR 10

void merge(int vetor[], int inicio, int fim);
void intercala(int vetor[], int inicio, int fim, int meio);

int main() {

	int vetor[TAMANHOVETOR], i;
	srand(time(NULL));

	for (i = 0; i <= (TAMANHOVETOR - 1); i++)
	{
		vetor[i] = rand() % 50;
	}

	printf("\nDESORDENADO\n");

	for (i = 0; i <= (TAMANHOVETOR - 1); i++)
	{
		printf("%d ", vetor[i]);
	}

	merge(vetor, 0, TAMANHOVETOR - 1);

	printf("\nORDENADO\n");

	for (i = 0; i <= (TAMANHOVETOR - 1); i++)
	{
		printf("%d ", vetor[i]);
	}

	printf("\n\n");
	system("pause");
	return 0;
}

void merge(int vetor[], int inicio, int fim)
{
	int meio;

	if (inicio < fim)
	{
		meio = (inicio + fim) / 2;
		merge(vetor, inicio, meio);
		merge(vetor, (meio + 1), fim);
		intercala(vetor, inicio, fim, meio);
	}
}

void intercala(int vetor[], int inicio, int fim, int meio)
{
	int poslivre, inicio_vetor1, inicio_vetor2, i, aux[TAMANHOVETOR];

	inicio_vetor1 = inicio;
	inicio_vetor2 = meio + 1;
	poslivre = inicio;

	while (inicio_vetor1 <= meio && inicio_vetor2 <= fim)
	{
		if (vetor[inicio_vetor1] <= vetor[inicio_vetor2])
		{
			aux[poslivre] = vetor[inicio_vetor1];
			inicio_vetor1++;
		}
		else
		{
			aux[poslivre] = vetor[inicio_vetor2];
			inicio_vetor2++;
		}
		poslivre++;
	}

	for (i = inicio_vetor1; i <= meio; i++)
	{
		aux[poslivre] = vetor[i];
		poslivre++;
	}

	for (i = inicio_vetor2; i <= fim; i++)
	{
		aux[poslivre] = vetor[i];
		poslivre++;
	}

	for (i = inicio; i <= fim; i++)
	{
		vetor[i] = aux[i];
	}
}