#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NUMLETRAS 100
#define NUMFRASES 8000
//#define NUMFRASES 1000

int main()
{
	char frase[NUMFRASES][NUMLETRAS];
	char *aux;
	char *pfrase[NUMFRASES];
	int i, n, j;
	srand(time(NULL));

	//INSERÇÃO DE DADOS
	for (int i = 0; i < NUMFRASES; i++)
	{
		for (int j = 0; j < NUMLETRAS; j++)
		{
			frase[i][j] = 'A' + (rand() % 26);
			//printf("%c", frase[i][j]);
		}
		//printf("\n");
	}

	clock_t t;
	t = clock();
	for (i = 0; i < NUMFRASES; i++)
		pfrase[i] = &*frase[i];

	//BUBBLE SORT
	for (n = 1; n <= NUMFRASES; n++) //Laço para o tamanho do vetor
	{
		for (i = 0; i < (NUMFRASES - 1); i++) //Laço da 1ª até a penultima posição
		{
			if ((strcmp(frase[i], frase[i + 1])) > 0)
			{
				aux = pfrase[i];
				pfrase[i] = pfrase[i + 1];
				pfrase[i + 1] = aux;
			}
		}
	}

	t = clock() - t;
	double time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds 


	printf("\n");
	printf("Took %f seconds to execute \n", time_taken);

	system("pause");
	return 0;
}