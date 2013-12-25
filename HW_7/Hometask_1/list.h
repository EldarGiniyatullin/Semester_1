#pragma once

#include <iostream>

struct ListElement
{
    int number;
    ListElement *value;
    ListElement *next;
};

struct List
{
    ListElement *array;
    int number;
    ListElement *first;
};

void addValueList(int num, int value, List &mylist);

void printList(List mylist);
