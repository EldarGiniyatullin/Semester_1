#pragma once

#include <iostream>

struct ListElement
{
    int value;
    ListElement *next;
};

struct List
{
    ListElement *first;
};

void addValueList(int i, List &mylist);

void removeValueList(int i, List &mylist);

void printList(List mylist);
