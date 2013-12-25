#include <iostream>

using namespace std;

int partition(int curr, int sum, int number, int *a)
{
    if ((sum == number) && (curr > 2))
    {
        cout <<  number << " = " << a[1];
        for (int j = 2; j < curr; j++)
        cout << " + " << a[j];
        cout << "\n";
    }
    else if (sum < number)
    {
            for(int i = 1; (i <= number - sum) && (i <= a[curr - 1]); i++)
            {
                a[curr] = i;
                partition(curr + 1, sum + i, number, a);
            }
    }
}

int main()
{
    int *a = new int [1000];
    a[0] = 65535;
    cout << "Enter a number: ";
    unsigned int number = 0;
    cin >> number;
    cout << "\n";
    partition(1, 0, number, a);
    delete[] a;
}



