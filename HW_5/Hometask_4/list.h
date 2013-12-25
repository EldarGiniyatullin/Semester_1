#pragma once

#include "userstring.h"

struct ListElement
{
    MyString name;
    MyString number;
    ListElement *next;
};

struct List
{
    ListElement *first;
    ListElement *last;
};

ListElement createNewElement(MyString word, MyString number);

List createNewList();

void addValueList(MyString word, MyString number, List &mylist);

void printList(List mylist);

void deleteList(List &mylist);
