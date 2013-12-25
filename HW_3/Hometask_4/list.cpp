#include "list.h"
#include <iostream>

using namespace std;

void printList(List mylist)
{
    cout << "\n";
    ListElement *curr = mylist.first;
    if (mylist.first == NULL)
    {
        cout << "No elements in the list";
    }
    else
    {
        while(curr)
        {
            cout << curr->value << " ";
            curr = curr->next;
        }
    }
    delete[] curr;
}

void removeValueList(int i, List &mylist)
{
    ListElement *curr;
    if (mylist.first != NULL)
    {
        curr = mylist.first;
        if (curr->value == i)
        {
            ListElement *p = mylist.first;
            mylist.first = mylist.first->next;
            p->next = NULL;
            delete p;
        }
        else
        {
            bool mark = true;
            while (mark)
            {
                if (curr->next == NULL)
                {
                    mark = false;
                }
                else if (curr->next->value == i)
                {
                    ListElement *p = curr->next;
                    curr->next = curr->next->next;
                    p->next = NULL;
                    delete p;
                    mark = false;
                }
                else if (curr->next->value < i && curr->value > i)
                {
                    break;
                }
                if (mark)
                {
                    curr = curr->next;
                }
            }
        }
    }
}


void addValueList(int i, List &mylist)
{
    ListElement *newEl = new ListElement;
    newEl->value = i;
    if (mylist.first == NULL)
    {
        mylist.first = newEl;
        newEl->next = NULL;
    }
    else if (i >= mylist.first->value)
    {
        newEl->next = mylist.first;
        mylist.first = newEl;
    }
    else if (i < mylist.first->value)
    {
        ListElement *tmp = mylist.first;
            while (tmp->next && i < tmp->next->value)
            {
                tmp = tmp->next;
            }
        if (!tmp->next)
        {
            tmp->next = newEl;
            newEl->next = NULL;
        }
        else newEl->next = tmp->next;
        tmp->next = newEl;
    }
}
