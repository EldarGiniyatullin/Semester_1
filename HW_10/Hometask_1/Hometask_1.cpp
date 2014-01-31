#include <iostream>
#include <fstream>
#include "codehuffman.h"

using namespace std;

int main()
{
    ifstream fin("text.txt");
    if (!fin.is_open())
    {
        cout << "Couldn\'t open file \"text.txt\"";
    }
    else
    {
        huffmanCoding(fin);
        cout << "The result added to \"HuffmanCode.txt\"";
    }
}
