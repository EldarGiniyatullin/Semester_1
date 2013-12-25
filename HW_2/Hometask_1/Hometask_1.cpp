#include <iostream>

using namespace std;

int fib(int n)
{
    if (n == 1 || n == 2)
    {
        return 1;
    }
    else
        return fib(n - 1) + fib(n - 2);
}

int main()
{
    cout << "How many Fibonacci numbers do you need? ";
    int n = 0;
    cin >> n;
    cout << "1 ";
    if (n > 1)
    {
        int fib1 = 0;
        int fib2 = 1;
        for (int i = 2; i <= n; i++)
        {
            int fib3 = fib1 + fib2;
            cout << fib3 << " ";
            fib2 = fib3;
            fib1 = fib3 - fib1;
        }
    }
    cout << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << fib(i) << " ";
    }
}

