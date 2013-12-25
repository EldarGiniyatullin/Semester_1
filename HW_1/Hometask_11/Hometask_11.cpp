#include <iostream>

using namespace std;

void quickSort(int *array, int first, int last)
{
    int x = array[first + (last - first) / 2];
    int i = first;
    int j = last;
    while(i <= j)
    {
        while(array[i] < x)
        {
            i++;
        }
        while(array[j] > x)
        {
            j--;
        }
        if(i <= j)
        {
            swap(array[i], array[j]);
            i++;
            j--;
        }
    }
    if (first < j)
        quickSort(array, first, j);

    if (i < last)
        quickSort(array, i, last);
}


int main()
{
    const int maxLen = 1000;
    int arrLen;
    cout << "Enter the length of array: ";
    cin >> arrLen;
    cout << "Enter the array you need to sort: ";
    int arr[maxLen];
    for(int i = 0; i < arrLen; i++)
    {
        cin >> arr[i];
    }
    quickSort(arr, 0, arrLen - 1);
    for(int i = 0; i < arrLen; i++)
    {
        cout << arr[i] << " ";
    }
}
