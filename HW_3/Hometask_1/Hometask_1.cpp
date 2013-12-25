#include <stdio.h>
#include <stdlib.h>

int main()
{
    const int ASCII = 61;
    int *string1 = new int[ASCII];
    for (int i = 0; i < ASCII; i++)
    {
        string1[i] = 0;
    }
    printf("Enter the first string: ");
    char c;
    while((c = getchar()) != '\n')
    {
        string1[c - 'A']++;
    }
    printf("\nEnter the second string: ");
    bool isTrue = true;
    while((c = getchar()) != '\n')
    {
        string1[c - 'A']--;
        if (string1[c - 'A'] < 0)
        {
            printf("\nIt is impossible.");
            isTrue = false;
            break;
        }
    }
    if (isTrue)
    {
        for(int i = 0; i < ASCII; i++)
        {
            if (string1[i] != 0)
            {
                printf("\nIt is impossible.");
                isTrue = false;
                break;
            }
        }
    }
    if (isTrue) printf("\nIt is possible.");
    delete[] string1;
}

