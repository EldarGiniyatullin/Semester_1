#include "myhashfunction.h"
#include "list.h"
#include "userstring.h"
#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;

HashData createHashData(int (*function)(MyString&))
{
    HashData currHash;
    for (int i = 0; i < 1000; i++)
    {
        currHash.hashTable[i] = NULL;
    }
    currHash.hashFunction = *function;
    return currHash;
}


void deleteHashData(HashData &currHash)
{
    currHash.hashFunction = NULL;
    for (int i = 0; i < 1000; i++)
    {
        while (currHash.hashTable[i] != NULL)
        {
            Element *tmp = currHash.hashTable[i]->next;
            //deleteString(currHash.hashTable[i]->element->number);
            //deleteString(currHash.hashTable[i]->element->name);
            delete currHash.hashTable[i];
            currHash.hashTable[i] = tmp;
        }
    }
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
}

void hashing(MyString &word, ListElement *elem, HashData &currHash)
{
    int hashValue = currHash.hashFunction(word);
    Element **tmp = &(currHash.hashTable[hashValue]);
    while (*tmp)
    {
        if (areEqual(elem->name, (*tmp)->element->name))
        {
            break;
        }
        else tmp = &((*tmp)->next);
    }
    if ((*tmp) == NULL)
    {
        Element *newEl = new Element;
        *tmp = newEl;
        newEl->element = elem;
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
                printString(tmp->element->number);
                cout << " ";
                printString(tmp->element->name);
                tmp = tmp->next;
            }
            cout << std::endl;
        }
    }
}
