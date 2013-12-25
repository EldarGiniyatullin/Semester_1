#include <stdio.h>
#include <math.h>
#include <stdlib.h>

using namespace std;

double expon(int a, int n)
{
    if (n < 0)
    {
        n = abs(n);
        return 1. / expon(a, n);
    }
    if (abs(n) == 0)
        return 1;
    else if (abs(n) % 2 == 0)
        return expon(a, abs(n) / 2) * expon(a, abs(n) / 2);
    else if (abs(n) % 2 == 1)
        return expon(a, abs(n) - 1) * a;
}

int main()
{
    printf("Enter a ^ n: a = ");
    int b = 0;
    scanf("%d", &b);
    printf("\nn = ");
    int c = 0;
    scanf("%d", &c);
    printf("\na ^ n = %f", expon(b, c));

}

