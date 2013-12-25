#include <iostream>
#include <fstream>
#include "userstring.h"
#include "list.h"
#include "myhashfunction.h"

using namespace std;

int main()
{
    ifstream fin("text2.txt"); // для работы с большим текстом подключите здесь text.txt
    if (!fin.is_open())
    {
        cout << "Couldn\'t open file";
    }
    else
    {
        char ch;
        HashData currHash = createHashData();
        while (!fin.eof())
        {
            fin.get(ch);
            while (!((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || fin.eof()))
            {
                fin.get(ch);
            }
            if (!fin.eof())
            {
                fin.putback(ch);
                MyString word = createNew();
                readWord(word, yes, fin);
                hashing(word, currHash);
                deleteString(word);
            }
        }
        fin.close();
        refreshMaxInf(currHash);
        printHashTable(currHash);
        printHashDataInf(currHash);
        deleteHashData(currHash);
    }
}

