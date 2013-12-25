#include "myhashfunction.h"
#include "list.h"
#include "userstring.h"
#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;

int myFunc1(MyString &string)
{
    int hashCode = 0;
    MySymbol **tmp = &string.first;
    for (int i = 0; i < string.length; i++)
    {
        hashCode = (hashCode + 31 * ((int)((*tmp)->symbol))) % 1000;
        tmp = &((*tmp)->next);
    }
    return hashCode;
}

HashData createHashData()
{
    HashData currHash;
    for (int i = 0; i < 1000; i++)
    {
        currHash.hashTable[i] = NULL;
    }
    currHash.totalValues = 1000;
    currHash.hashFunction = myFunc1;
    return currHash;
}


void deleteHashData(HashData &currHash)
{
    currHash.hashFunction = NULL;
    currHash.totalValues = 0;
    for (int i = 0; i < 1000; i++)
    {
        while (currHash.hashTable[i] != NULL)
        {
            Element *tmp = currHash.hashTable[i]->next;
            deleteString(currHash.hashTable[i]->string);
            delete currHash.hashTable[i];
            currHash.hashTable[i] = tmp;
        }
    }
    delete[] currHash.hashTable;
}

void hashing(MyString &word, HashData &currHash)
{
    int hashValue = currHash.hashFunction(word);
    Element **tmp = &(currHash.hashTable[hashValue]);
    while (*tmp)
    {
        if (areEqual(word, (*tmp)->string))
        {
            (*tmp)->number++;
            break;
        }
        else tmp = &((*tmp)->next);
    }
    if ((*tmp) == NULL)
    {
        Element *newEl = new Element;
        *tmp = newEl;
        newEl->number = 1;
        newEl->string = clone(word);
        newEl->next = NULL;

    }
    tmp = NULL;
}

void printHashTable(HashData currHash)
{
    for (int i = 0; i < 1000; i++)
    {
        if (currHash.hashTable[i] != NULL)
        {
            Element *tmp = currHash.hashTable[i];
            while (tmp)
            {
                printString(tmp->string);
                cout << "(" << tmp->number << ") ";
                tmp = tmp->next;
            }
            cout << std::endl;
        }
    }
}
