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
    int storedData;          // сколько слов хранится
    int totalValues;        // всего ячеек
    int usedValues;        // занятых ячеек
    List maxList;         // значения ключей у максимальных цепей
    int maxListNumber;   // максимальная длина цепочки
    int (*hashFunction)(MyString&);
};

HashData createHashData();

void deleteHashData(HashData &currHash);

void hashing(MyString &word, HashData &currHash);

void refreshMaxInf(HashData &currHash);

void countMaxInf(HashData &currHash);

void printHashTable(HashData currHash);

void printHashDataInf(HashData currHash);
