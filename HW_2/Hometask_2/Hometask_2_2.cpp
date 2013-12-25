#include <iostream>
#include <math.h>

using namespace std;

double expon(int a, int n)
{
    if (n < 0)
    {
        n = abs(n);
        return 1. / expon(a, n);
    }
    if (abs(n) == 0)
        return 1;
    else if (abs(n) % 2 == 0)
        return expon(a, abs(n) / 2) * expon(a, abs(n) / 2);
    else if (abs(n) % 2 == 1)
        return expon(a, abs(n) - 1) * a;
}

int main()
{
    cout << "Enter a ^ n: a = ";
    int b = 0;
    cin >> b;
    cout << "\nn = ";
    int c = 0;
    cin >> c;
    if (c >= 0)
        cout << "\na ^ n = " << expon(b, c);
    else
        cout << "\na ^ n = " << expon(b, c);

}

