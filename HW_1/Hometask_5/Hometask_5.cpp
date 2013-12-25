#include <iostream>

using namespace std;

int main()
{
    cout << "Enter the length of array: ";
    int length = 0;
    cin >> length;
    cout << "\nEnter the array of \'[\' and \']\': ";
    const int maxLen = 1000;
    char array[maxLen];
    int balance = 0;
    for (int i = 0; i < length; i++)
    {
        cin >> array[i];
        if (array[i] == '[')
        {
            balance++;
        }
        else if (array[i] == ']')
        {
            balance--;
        }
        if (balance < 0)
        {
            break;
        }
    }
    if (balance != 0)
    {
        cout << "\nInvalid array";
    }
    else
        cout << "\nValid array";
}

