#pragma once

using namespace std;


struct ListElement
{
    int value;
    ListElement *next;
};

struct List
{
    ListElement *first;
};

List removeValueList(int i, List &myList);

List addValueUpSortedList(int i, List &myList);

void addValueList(int i, List &myList);

void printList(List &myList);

void sortUpInceptionList(List &myList);
