#include <stdio.h>

using namespace std;

int main()
{
    printf("Enter the number: ");
    const int length = 10;
    int array[length] = {0};
    char digit;
    int min = 10;
    while ((digit = getchar()) != '\n')
    {
        if (digit - '0' < min && digit - '0' != 0)
        {
            array[min]++;
            min = digit - '0';
        }
        else
            array[digit - '0']++;
    }
    printf("\n%d", min);
    for (int i = 0; i < 10; i++)
    {
        if (array[i] != 0)
        {
            for (int j = 1; j <= array[i]; j++)
            {
                 printf("%d", i);
            }
        }
    }
}

