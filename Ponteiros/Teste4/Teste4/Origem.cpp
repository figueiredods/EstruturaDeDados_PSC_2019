#include <stdio.h>
#include <stdlib.h>

int main()
{
	int x, y;
	int *px = &x;

	*px = 14;
	y = *px;

	printf("y = %d\n", y);

	system("pause");
	return 0;
}




