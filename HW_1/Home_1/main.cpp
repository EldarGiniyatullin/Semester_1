#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main()
{	int x;
	printf("Enter x\n");
	scanf("%d", &x);
	int sqrX = x * x;
	printf("x^4 + x^3 + x^2 + x = %d", (sqrX + 1) * (sqrX + x));
}
