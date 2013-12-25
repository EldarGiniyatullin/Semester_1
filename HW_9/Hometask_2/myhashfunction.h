#pragma once

#include "list.h"
#include "userstring.h"

struct Element
{
    int number;
    MyString string;
    Element *next;
};

struct HashData
{
    Element *hashTable[1000];
    int totalValues;
    int (*hashFunction)(MyString&);
};

HashData createHashData();

void deleteHashData(HashData &currHash);

void hashing(MyString &word, HashData &currHash);

void printHashTable(HashData currHash);

