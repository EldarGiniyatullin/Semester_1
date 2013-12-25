#include <stdio.h>


int main()
{
    int  dividend, divisor;
    printf("Enter dividend and divisor: ");
    scanf("%d, %d", &dividend, &divisor);
    if (divisor == 0)
    {
        printf("\nDivisor cannot equal zero");
    }
         else
    {
        int quotient = 0;
        while(dividend <= divisor)
        {
            dividend -= divisor;
            quotient++;
        }
        printf("%d = %d*%d + %d", quotient * divisor + dividend, divisor, quotient, dividend);
    }

}

