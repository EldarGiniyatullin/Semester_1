#include "list.h"
#include <iostream>

using namespace std;

void printList(List mylist)
{
    cout << "\n";
    if (mylist.first == NULL)
    {
        cout << "No elements in the list";
    }
    else
    {
        ListElement *curr = mylist.first;
        while(curr)
        {
            cout << curr->value << "\n";
            curr = curr->next;
        }
    }
}


void addValueList(int value, List &mylist)
{
    ListElement *newEl = new ListElement;
    newEl->value = value;
    newEl->next = mylist.first;
    mylist.first = newEl;
}

void deleteList(List &mylist)
{
    ListElement *tmp = mylist.first;
    while (mylist.first)
    {
        mylist.first = mylist.first->next;
        delete tmp;
        tmp = mylist.first;
    }
}
