#include <stdio.h>

int swap(int &j, int &c)
{
    j = j ^ c;
    c = j ^ c;
    j = j ^ c;
}
int inverse(int *array, int first, int last)
{
    for (int j = first; j <= (first - 1 + ((last - first + 1) / 2)); j++)
    {
        swap(array[j], array[last + first - j]);
    }
}

int main()
{
   const int length = 1000;
   int arrLen;
   int groupLen;
   printf("Enter m, n:");
   scanf("%d %d", &groupLen, &arrLen);
   printf("\nArray: ");
   int arr[arrLen + 1];
   for (int i = 1; i <= arrLen; i++)
   {
       scanf(" %d", &arr[i]);
   }
   printf("\n");
   inverse(arr, 1, groupLen);
   inverse(arr, groupLen + 1, arrLen);
   inverse(arr, 1, arrLen);
   for (int i = 1; i <= arrLen; i++)
   {
       printf("%d ", arr[i]);
   }
}

