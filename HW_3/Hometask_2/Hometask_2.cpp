#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    cout << "Enter the length of side: ";
    int side = 0;
    cin >> side;
    cout << endl;
    int **a = new int *[side + 1];
    for (int i = 1; i <= side; i++)
    {
        a[i] = new int [side + 1];
    }
    cout << "Enter the array:" << endl;
    for (int i = 1; i <= side; i++)
         for (int j = 1; j <= side; j++)
         {
             cin >> a[i][j];
         }
    {
        int horizontal = 1;
        int vertical = -1;
        int reverse = -1;
        int printLen = 1;
        int currRow = side / 2 + 1;
        int currColumn = side / 2 + 1;
        cout << a[currRow][currColumn] << " ";
        currColumn++;
        while (printLen != side)
        {
            int printed = 0;
            for(int i = currColumn; printed < printLen; i += horizontal)
            {
                printed++;
                cout << a[currRow][i] << " ";
                currColumn += horizontal;
            }
            currColumn -= horizontal;
            horizontal *= reverse;
            currRow += vertical;
            printed = 0;
            for (int i = currRow; printed < printLen; i += vertical)
            {
                printed++;
                cout << a[i][currColumn] << " ";
                currRow += vertical;
            }
            currRow -= vertical;
            vertical *= reverse;
            currColumn += horizontal;
            printLen++;
        }
        if (side != 1)
        {
            for (int i = 2; i <= side; i++)
            {
                cout << a[side][i] << " ";
            }
        }
    }
    for (int i = 1; i <= side; i++)
    {
        delete[] a[i];
    }
    delete[] a;
}

