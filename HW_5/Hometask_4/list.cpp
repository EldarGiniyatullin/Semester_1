#include "list.h"
#include "userstring.h"
#include <iostream>

using namespace std;

List createNewList()
{
    List newList;
    newList.first = NULL;
    newList.last = NULL;
    return newList;
}

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
            printString(curr->name);
            cout << " ";
            printString(curr->number);
            cout << "\n";
            curr = curr->next;
        }
    }
}

ListElement createNewElement(MyString word, MyString number)
{
    ListElement *newElement = new ListElement;
    newElement->next = NULL;
    newElement->name = clone(word);
    newElement->number = clone(number);
}

void addValueList(MyString word, MyString number, List &mylist)
{
    ListElement *newEl = new ListElement;
    newEl->name = clone(word);
    newEl->number = clone(number);
    newEl->next = mylist.first;
    mylist.first = newEl;
    if (!(newEl->next))
    {
        mylist.last = newEl;
    }
}

void deleteList(List &mylist)
{
    ListElement *tmp = mylist.first;
    while (mylist.first)
    {
        mylist.first = mylist.first->next;
        deleteString(tmp->name);
        deleteString(tmp->number);
        delete tmp;
        tmp = mylist.first;
    }
}
