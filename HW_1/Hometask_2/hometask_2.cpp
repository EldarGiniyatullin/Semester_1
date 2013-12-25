#include <stdio.h>

int main()
{
    int dividend = 0;
    int divisor = 0;
    printf("Enter dividend and divisor: ");
    scanf("%d %d", &dividend, &divisor);
    if (divisor == 0)
    {
        printf("\nDivisor cannot equal zero");
    }
    else {
         int quotient = 0;
         if (dividend > 0)
         {
             if (divisor > 0)
             {
                 while (divisor * (quotient + 1) <= dividend)
                 {
                    quotient++;
                 }
             }
             else
             {
                  while (divisor * (quotient - 1) <= dividend)
                  {
                        quotient--;
                  }
             }
         }
         else if (dividend < 0)
         {
             if (divisor > 0)
             {
                 while (divisor * quotient >= dividend)
                 {
                     quotient--;
                 }
             }
             else
             {
                 while (divisor * quotient >= dividend)
                 {
                     quotient++;
                 }
             }
         }
         else if (dividend == 0)
             quotient = 0;
         printf("Quotient equals %d", quotient);
         }
}

