#include <iostream>

using namespace std;

int swap(int &j, int &c)
{
    if (j != c)
    {
        j = j ^ c;
        c = j ^ c;
        j = j ^ c;
    }
}

int heapSort(int *array, int length)
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
    cout << "How many elements? ";
    int length = 0;
    cin >> length;
    int *arr = new int[length];
    cout << "\nEnter them: ";
    for (int i = 1; i <= length; i++)
    {
        cin >> arr[i];
    }
    heapSort(arr, length);
    cout << "\n";
    for (int i = 1; i <= length; i++)
    {
        cout << arr[i] << " ";
    }
}

