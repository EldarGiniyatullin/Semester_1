#pragma once

struct ListElement
{
    int value;
    ListElement *next;
};

struct List
{
    ListElement *first;
};

void addValueList(int value, List &mylist);

void printList(List mylist);

void deleteList(List &mylist);
