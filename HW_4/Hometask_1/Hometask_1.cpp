#include <iostream>

using namespace std;

void swap(int &j, int &c)
{
    if (j != c)
    {
        j = j ^ c;
        c = j ^ c;
        j = j ^ c;
    }
}

void heapSort(int *array, int length)
{
    for (int i = (length + 1) / 2 - 1; i >= 1; i--)
    {
        if (array[i] < array[2 * i])
                swap(array[i], array[2 * i]);
        if (array[i] < array[(2 * i) + 1])
                swap(array[i], array[(2 * i) + 1]);
        if (array[2 * i] > array[(2 * i) + 1])
                swap(array[2 * i], array[(2 * i) + 1]);
    }
    if (length > 1)
    {
        swap(array[1], array[length]);
        heapSort(array, length - 1);
    }
}

int main()
{
    cout << "Enter a length of array ";
    int length = 0;
    cin >> length;
    cout << "Enter an array ";
    int *array = new int[length + 1];
    for (int i = 1; i <= length; i++)
    {
        cin >> array[i];
    }
    bool isMax = false;
    int max = 0;
    if (length == 2 && array[1] == array[2])
    {
        max = array[1];
        isMax = true;
    }
    else if (length > 2)
    {
        heapSort(array, length);
        for (int i = length - 1; i >= 1; i--)
        {
            if (array[i] == array[i + 1])
            {
                max = array[i];
                isMax = true;
                break;
            }
        }
    }
    if (isMax)
    {
        cout << "\nThe maximal repeating number is " << max;
    }
    else
    {
        cout << "\nNo any repeating number";
    }
    delete[] array;
}

