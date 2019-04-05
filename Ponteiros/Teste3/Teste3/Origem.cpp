#include <stdio.h>
#include <stdlib.h>

int main()
{
	int x = 4, y = 7;
	int *px, *py;

	printf("&x = %p\t x = %d\n", &x, x);
	printf("&y = %p\t y = %d\n\n", &y, y);

	px = &x;
	py = &y;

	printf("px = %p\t *px = %d\n", px, *px);
	printf("py = %p\t *py = %d\n\n", py, *py);

	system("pause");
	return 0;
}

