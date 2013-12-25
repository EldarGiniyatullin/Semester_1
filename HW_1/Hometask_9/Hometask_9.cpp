#include <stdio.h>

using namespace std;

int main()
{
    printf("Enter a ^ n :\n");
    printf("a = ");
    int base;
    scanf("%d", &base);
    printf("\nn = ");
    int index;
    scanf("%d", &index);
    if (index == 0)
        printf("a ^ n = 1");
    else if (index > 0)
    {
        unsigned int power = 1;
        for (int i = 1; i <= index; i++)
        {
            power *= base;
        }

        printf("a ^ n = %d", power);
    }
    else if (index < 0)
    {
        double power = 1;

        for (int i = 0; i >= index; i--)
        {
            power /= base;
        }

        printf("a ^ n = %.50f", power);
    }
}

