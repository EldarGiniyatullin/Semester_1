#include <iostream>
#include <math.h>

using namespace std;

void space(int j)
{
    int d = j;
    while (abs(d) > 0)
    {
        cout << " ";
        d /= 10;
    }
}

int main()
{
    cout << "Enter the maximal degree: ";
    int n = 0;
    cin >> n;
    cout << "\nEnter the coefficients: ";
    int *coefs = new int [n + 1];
    for (int i = n; i >= 0; i--)
    {
        cin >> coefs[i];
    }
    int tmp = 0;
    for (int i = n; i >= 0; i--)
    {
        if (coefs[i] != 0)
        {
            tmp = i;
            break;
        }
    }
    {
        if (coefs[tmp] < 0)
        {
           cout << " ";
        }
        space(coefs[tmp]);
        if (abs(coefs[tmp]) != 1)
        {
            cout << " ";
        }
        cout << tmp;
    }
    for (int i = tmp - 1; i > 1; i--)
    {
        if (coefs[i] != 0)
        {
            cout << " ";
            space(coefs[i]);
            if (abs(coefs[i]) != 1)
            {
                cout << " ";
            }
            cout << i;
        }
    }
    cout << "\n";
    {
        if (coefs[tmp] == 1)
        {
            cout << "x";
        }
        else if (coefs[tmp] == -1)
        {
            cout << "-x";
        }
        if (abs(coefs[tmp]) != 1)
        {
            cout << coefs[tmp] << "x";
        }
        if (tmp > 1)
        {
            space(tmp);
        }
    }
    for (int i = tmp - 1; i >= 0; i--)
    {
        if (coefs[i] != 0)
        {

            if (coefs[i] > 0)
            {
                cout << "+";
            }
            if (coefs[i] < 0)
            {
                cout << "-";
            }
            if ((abs(coefs[i]) != 1 && i > 0) || i == 0)
            {
                cout << abs(coefs[i]);
            }
            if (i > 0)
            {
                cout << "x";
            }
            if (i > 1)
            {
                space(i);
            }
        }
    }
    delete[] coefs;
}


