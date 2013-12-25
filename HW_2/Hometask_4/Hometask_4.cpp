#include <iostream>

using namespace std;

int binHCD(int a, int b)
{
    if (b == 0)
        return a;
    if (a == 0)
        return b;
    if (a == b)
        return a;
    if (a == 1 || b == 1)
        return 1;
    if (a % 2 == 0)
    {
        if  (b % 2 == 0)
            return 2 * binHCD(a / 2, b / 2);
        else
            return binHCD(a / 2, b);
    }
    if (b % 2 == 0 && a % 2 == 1)
        return binHCD(a, b / 2);
    else
    {
        if (a < b)
            return binHCD((b - a) / 2, a);
        else
            return binHCD((a - b) / 2, b);
    }
}

int swap(int &j, int &c)
{
    j = j ^ c;
    c = j ^ c;
    j = j ^ c;
}


struct Fraction
{
    int num;
    int den;
};

int heapSortFrac(Fraction *array, int length)
{
    for (int i = (length + 1) / 2 - 1; i >= 1; i--)
    {
        if (array[i].num * array[2 * i].den < array[2 * i].num * array[i].den)
                swap(array[i], array[2 * i]);
        if (array[i].num * array[(2 * i) + 1].den < array[(2 * i) + 1].num * array[i].den)
                swap(array[i], array[(2 * i) + 1]);
        if (array[2 * i].num * array[(2 * i) + 1].den > array[(2 * i) + 1].num * array[2 * i].den)
                swap(array[2 * i], array[(2 * i) + 1]);
    }
    if (length > 1)
    {
        swap(array[1], array[length]);
        heapSortFrac(array, length - 1);
    }
}




int main()
{
    cout << "Enter the maximal denominator: ";
    int number = 0;
    cin >> number;
    Fraction *array = new Fraction [(number * (number + 1) / 2) + 1];
    int curr = 0;
    for (int i = 2; i <= number; i++)
        for (int j = 1; j < i; j++)
        {
            if (binHCD(j, i) == 1)
            {
                curr++;
                array[curr].num = j;
                array[curr].den = i;
            }
        }
    heapSortFrac(array, curr);
    cout << "\n";
    for (int i = 1; i <= curr; i++)
    {
        cout << array[i].num << "/" << array[i].den << " ";
    }
}

