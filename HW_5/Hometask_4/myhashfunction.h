#pragma once

#include "list.h"
#include "userstring.h"

struct Element
{
    ListElement *element;
    Element *next;
};

struct HashData
{
    Element *hashTable[1000];
    int (*hashFunction)(MyString&);
};

HashData createHashData(int (*function)(MyString&));

void deleteHashData(HashData &currHash);

void hashing(MyString &word, ListElement *elem, HashData &currHash);

void refreshMaxInf(HashData &currHash);

void countMaxInf(HashData &currHash);

void printHashTable(HashData currHash);

void printHashDataInf(HashData currHash);
