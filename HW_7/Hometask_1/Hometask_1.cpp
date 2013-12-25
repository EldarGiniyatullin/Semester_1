#include <iostream>

using namespace std;

int mainWork(int curr, int *array)
{
    if (array[curr] > 3)
        return mainWork(array[curr] - 1, array);
    else return array[curr];
}

int main()
{
    cout << "Enter the number of students " << endl;
    int number = 0;
    cin >> number;
    cout << "Enter the number of students with works " << endl;
    int taskNumber = 0;
    cin >> taskNumber;
    cout << "Enter the information ";
    int *array = new int[number];
    for (int i = 0; i < number; i++)
    {
        array[i] = 0;
    }
    array[0] = 1;
    array[1] = 2;
    array[2] = 3;
    int tmp = 0;
    for (int i = 0; i < taskNumber; i++)
    {
        cin >> tmp;
        cin >> array[tmp - 1];
    }
    for (int i = 0; i < number; i++)
    {
        cout << i + 1 << " ";
        array[i] =  mainWork(i, array);
        if (array[i] != 0)
            cout << array[i];
        else
            cout << "has no work";
        cout << endl;
    }
    delete[] array;
}


