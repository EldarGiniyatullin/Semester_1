#include <stdio.h>

int fac(int c)
{
    if (c == 1 || c == 0)
        return 1;
    else return c * fac(c-1);
}

int main()
{

    int n;
    printf("Enter n =\n");
    scanf("%d", &n);
    unsigned long facIter = 1;
    if (n >= 2)
    {
        for (int i = 2; i<=n; i++)
        {
            facIter *= i;
        }
    }
    unsigned long facRecur = fac(n);
    printf("Iterative = %u\nRecursive = %u", facIter, facRecur);
}

