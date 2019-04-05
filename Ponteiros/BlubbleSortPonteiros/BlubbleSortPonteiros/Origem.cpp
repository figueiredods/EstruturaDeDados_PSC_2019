/*
Ordene nomes utilizando o BUBBLE SORT e empregando uma matriz de ponteiros.
Ao invés de ordenar os próprios nomes, iremos ordenar a matriz de ponteiros
onde cada elemento do ponteiro aponta para um nome.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOME_MAX 30
#define TAM_MAX 100

void bubblesort(char **p, int n);

int main()
{
	char nomes[NOME_MAX][TAM_MAX];
	char *p[30];
	int n, i;

	for (n = 0;; n++)
	{
		printf("Digite um nome ou [ENTER] para encerrar:");
		gets_s(nomes[n]);
		if (strlen(nomes[n]) == 0)
			break;
		p[n] = nomes[n];
	}

	printf("\n\nLista Original:\n");
	for (i = 0; i < n; i++)
		printf("%s\n", p[i]);

	bubblesort(p,n);

	printf("\n\nLista Ordenada:\n");
	for (i = 0; i < n; i++)
		printf("%s\n", p[i]);

	system("pause");
	return 0;
}

void bubblesort(char **p, int n)
{
	char *aux;
	int i, j;

	for (i=0;i<n-1;i++)
	{
		for (j = i+1; j<n ; j++)
		{
			if (strcmp(p[i], p[j]) > 0)
			{
				aux = *(p + i);
				*(p + i) = *(p + j);
				*(p + j) = aux;
			}
		}
	}

}