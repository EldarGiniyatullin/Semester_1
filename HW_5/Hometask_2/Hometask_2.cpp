#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;

void sign(double number)
{
    int bit = 1;
    number = (unsigned long long)number >> 63;
    ((unsigned long long)number & bit) ? cout << "-" : cout << "+";
}

void mantissa(double number)
{
    double mantissa = 1;
    unsigned long long exponenta = *(unsigned long long*)&number;
    exponenta <<= 1;
    exponenta >>= 53;
    exponenta -= 1023;
    unsigned long long temp = *(unsigned long long*)&number;
    int bit = 0b1;
    temp >>= 40;
    double exp = 1 / pow(2, 12);
    for (int i = 1; i <= 12; i++)
    {
        mantissa = mantissa + (temp & bit) * exp;
        temp >>= 1;
        exp = exp * 2.0;
    }
    cout << mantissa;
}

void exponenta(double number)
{
    unsigned long long exponenta = *(unsigned long long*)&number;
    exponenta <<= 1;
    exponenta >>= 53;
    cout << "*2^(";
    if (exponenta >= 1023)
        cout << exponenta - 1023;
    else
        cout << "-" << 1023 - exponenta;
    cout << ")";
}

int main()
{
    printf("Enter a number ");
    double number;
    scanf("%lf", &number);
    printf("\n");
    sign(number);
    mantissa(number);
    exponenta(number);
}
