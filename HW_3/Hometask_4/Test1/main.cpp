#include <iostream>
#include <stdlib.h>

using namespace std;

struct ListEl
{
    int value;
    ListEl *next;
};

struct List
{
    ListEl *first;
};




void printList(List mylist)
{
    cout << "\n";
    ListEl *curr = new ListEl;
    curr = mylist.first;
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

List addValueList(int i, List &mylist)
{
    ListEl *newEl = new ListEl;
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
        ListEl *tmp = new ListEl;
        tmp->next = mylist.first;
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
    return mylist;
}

List removeValueList(int i, List &mylist)
{
    ListEl *curr = new ListEl;
    curr = mylist.first;
    if (mylist.first != NULL)
    {
        if (curr->value == i)
        {
            ListEl *p = mylist.first;
            mylist.first = mylist.first->next;
            p->next = NULL;
            delete &p;
        }
        else
        {
            bool mark = true;
            while (mark)
            {
                if (curr->next->value == i)
                {
                    ListEl *p = curr->next;
                    curr->next = curr->next->next;
                    p->next = NULL;
                    delete &p;
                    mark = false;
                }
                else if (curr->value > i && curr->next->value < i)
                {
                    break;
                }
                if (curr->next == NULL)
                    mark = false;
                if (mark)
                {
                    curr = curr->next;
                }
            }
        }
    }
    return mylist;
}

int main()
{
        cout << "Hello\n";
        int n = 0;
        cin >> n;
        List mylist;
        mylist.first = new ListEl;
        mylist.first->value = 2 * n;
        mylist.first->next = NULL;
        if (n > 1)
        {
            ListEl *tmp = mylist.first;
            mylist.first->next = tmp;
            tmp = mylist.first;
            for (int i = 1; i < n; i++)
            {
                ListEl *newEl = new ListEl;
                newEl->value = 2 * (n - i);
                newEl->next = NULL;
                tmp->next = newEl;
                tmp = tmp->next;
            }
        }
        printList(mylist);
        cout << "\nEnter value :\n";
        cin >> n;
        removeValueList(n, mylist);
        printList(mylist);
        cin >> n;
        removeValueList(n, mylist);
        printList(mylist);
        cin >> n;
        removeValueList(n, mylist);
        printList(mylist);
}

