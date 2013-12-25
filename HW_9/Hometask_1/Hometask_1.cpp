#include <fstream>
#include <iostream>
#include "userstring.h"
#include "list.h"
#include "myhashfunction.h"

using namespace std;

int main()
{
    fstream fin("input1.txt");
    if (!fin.is_open())
    {
        cout << "Couldn\'t open file input1.txt";
    }
    else
    {
        char ch = '\0';
        MyString temp = createNewString();
        HashData currHash = createHashData();
        while (!fin.eof())
        {
            fin.get(ch);
            if (!fin.eof())
            {
                fin.putback(ch);
                readString(temp, '\n', fin);
                hashing(temp, currHash);
                deleteString(temp);
            }
        }
        fin.close();
        fin.open("input2.txt");
        if (!fin.is_open())
        {
            cout << "Couldn\'t open file input2.txt";
        }
        else
        {
            ofstream fout;
            fout.open("output.txt", ios_base::trunc);
            int value = 0;
            Element* curr = NULL;
            while (!fin.eof())
            {
                fin.get(ch);
                if (!fin.eof())
                {
                    fin.putback(ch);
                    readString(temp, '\n', fin);
                    value = currHash.hashFunction(temp);
                    if (!fin.eof())
                    {
                        if (currHash.hashTable[value])
                        {
                            curr = currHash.hashTable[value];
                            while (curr)
                            {
                                if (!areEqual(temp, curr->string))
                                    curr = curr->next;
                                else
                                {
                                    printString(temp, fout);
                                    fout.put('\n');
                                    break;
                                }
                            }
                        }
                        deleteString(temp);
                    }
                }
            }
            fout.close();
        }
        deleteHashData(currHash);
        fin.close();
        cout << "Information successfully saved.\n";
    }
}

