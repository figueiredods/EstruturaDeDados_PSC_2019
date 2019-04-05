#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *pi;

	pi = (int *) malloc(sizeof(int));

	puts("Digite um numero: ");
	scanf_s("%d", pi);

	printf("\nVoce digitou o numero %d\n", pi);

	free(pi);

	system("pause");
	return 0;
}

