#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

void truefication(bool *mas);

int main()
{
    char symbol;
    ifstream fin("text.txt");
    ofstream fout("result.txt", ios_base::out);
    if (!fin.is_open())
        cout << "Could not open";
    else
    {
        const int number = 128;
        bool *symbolsUsed = new bool[number];
        truefication(symbolsUsed);
        while (!fin.eof())
        {
            fin.get(symbol);
            while (symbol != '\n' && symbol != 32)
            {
                if ((symbol >= 'A' && symbol <= 'Z') || (symbol >= 'a' && symbol <= 'z'))
                {
                    if (symbolsUsed[symbol])
                    {
                        symbolsUsed[symbol] = false;
                        symbolsUsed[symbol - 32 * ((symbol - 'a' + 1) / abs(symbol - 'a' + 1))] = false;
                        fout << symbol;
                        cout << symbol;
                    }
                    if (!fin.eof())
                    {
                        fin.get(symbol);
                    }
                }
                else
                {
                    fout << symbol;
                    cout << symbol;
                    if (!fin.eof())
                    {
                        fin.get(symbol);
                    }
                }
            }
            fout << symbol;
            cout << symbol;
            truefication(symbolsUsed);
        }
        delete[] symbolsUsed;
    }
    fin.close();
    fout.close();
    return 0;
}

void truefication(bool *mas)
{
    for (int i = 'A'; i <='Z'; i++)
    {
        mas[i] = true;
        mas[i + 'a' - 'A'] = true;
    }
}


