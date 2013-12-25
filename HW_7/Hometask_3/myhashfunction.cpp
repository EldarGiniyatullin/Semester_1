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

int myFunc2(MyString &string)
{
    int hashCode = 0;
    MySymbol **tmp = &string.first;
    for (int i = 0; i < string.length; i++)
    {
        hashCode = (hashCode + 4 * ((int)((*tmp)->symbol))) % 1000;
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
    currHash.usedValues = 0;
    currHash.maxList.first = NULL;
    currHash.maxListNumber = 0;
    currHash.storedData = 0;
    currHash.hashFunction = myFunc1;
    return currHash;
}


void deleteHashData(HashData &currHash)
{
    currHash.hashFunction = NULL;
    currHash.totalValues = 0;
    currHash.usedValues = 0;
    deleteList(currHash.maxList);
    currHash.maxListNumber = 0;
    currHash.storedData = 0;
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

void refreshHashData(HashData &currHash)
{
    for (int i = 0; i < 1000; i++)
    {
        while (currHash.hashTable[i] != NULL)
        {
            Element *tmp = currHash.hashTable[i]->next;
            delete currHash.hashTable[i];
            currHash.hashTable[i] = tmp;
        }
    }
    currHash.totalValues = 0;
    currHash.usedValues = 0;
    deleteList(currHash.maxList);
    currHash.maxListNumber = 0;
    currHash.storedData = 0;
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

void refreshMaxInf(HashData &currHash)
{
    for (int i = 0; i < 1000; i++)
    {
        Element *curr = currHash.hashTable[i];
        int tmp = 0;
        while (curr)
        {
            tmp++;
            curr = curr->next;
        }
        if (tmp > 0)
        {
            currHash.usedValues++;
            currHash.storedData += tmp;
            if (tmp > currHash.maxListNumber)
            {
                deleteList(currHash.maxList);
                currHash.maxListNumber = tmp;
            }
            if (tmp == currHash.maxListNumber)
            {
                addValueList(i, currHash.maxList);
            }
        }
    }
}

void printHashDataInf(HashData currHash)
{
    cout << "Load factor = " << std::setprecision(6) << (float)(currHash.storedData * 1.0 / currHash.totalValues) << endl;
    cout << "Average length = " << std::setprecision(6) << (float)(currHash.storedData * 1.0 / currHash.usedValues) << endl;
    ListElement *max = currHash.maxList.first;
    while (max)
    {
        cout << "The key " << max->value << " has the maximal number of words (" << currHash.maxListNumber << ")" << " and includes words: " << endl;
        Element *curr = currHash.hashTable[max->value];
        while (curr)
        {
            cout << " ";
            printString(curr->string);
            cout << " ";
            curr = curr->next;
        }
        max = max->next;
        cout << endl;
    }
    cout << endl;
    cout << "Totally added " << currHash.storedData << " words" << endl;
    cout << "\"Empty\" keys number = " << currHash.totalValues - currHash.usedValues << endl;
}
