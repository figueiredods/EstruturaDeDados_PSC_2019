#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 50

int main()
{
	//O primeiro endereço de uma matriz é o endereço do primeiro
	//elemento desta matriz
	static int M[5] = {92,81,70,69,58};
	int i;

	//IMPRIME OS ELEMENTOS DA MATRIZ DE FORMA CONVENCIONAL
	for (i = 0; i < 5; i++)
		printf("%d\n", M[i]);

	printf("\n\n");

	//IMPRIME OS ELEMENTOS DA MATRIZ USANDO A NOTAÇÃO DE PONTEIROS
	for (i = 0; i < 5; i++)
		printf("%d\n", *(M + i));

	system("pause");
	return 0;
}