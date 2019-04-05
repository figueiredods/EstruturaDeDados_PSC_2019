#include <stdio.h>
#include <stdlib.h>

void reajusta20(float *preco, float *reajuste);

int main()
{
	float val_preco, val_reaj;
	do
	{
		printf("\nInsira o preco atual: ");
		scanf_s("%f", &val_preco);
		
		/* Envia os enderecos */
		reajusta20(&val_preco, &val_reaj); 

		printf("\n O preco novo eh %.2f\n", val_preco);
		printf("O aumento foi de %.2f\n", val_reaj);

	} while (val_preco != 0.0);

	system("pause");
	return 0;
}

void reajusta20(float *preco, float *reajuste)
{
	*reajuste = *preco * 0.2;
	*preco *= 1.2;

}

