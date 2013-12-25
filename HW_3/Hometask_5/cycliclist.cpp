#include <iostream>
#include "cycliclist.h"

using namespace std;

void createNumberCycList(int n, CycListElement *head)
{
    head->value = 1;
    CycListElement *curr = new CycListElement;
    curr->next = head;
    head->next = curr;
    head->value = 1;
    curr->value = n;
    n--;
    while (n > 1)
    {
        CycListElement *tmp = new CycListElement;
        tmp->next = head->next;
        tmp->value = n;
        head->next = tmp;
        n--;
    }
}

void printCycList(CycListElement *head)
{
    cout << "\n";
    CycListElement *curr = head;
    if (head->next == NULL)
    {
        cout << "No elements in the list";
    }
    else
    {
        cout << curr->value << " ";
        curr = curr->next;
        while(curr->next != head)
        {
            cout << curr->value << " ";
            curr = curr->next;
        }
        cout << curr->value << " ";
    }
}

int luckyNumberCycList(int n, CycListElement *head)
{
    int c = 1;
    CycListElement *curr = head;
    while (head->next != head)
    {
        while (c != n - 1)
        {
            curr = curr->next;
            c++;
        }
        if (curr->next == head)
        {
            head = head->next;
        }
        CycListElement *tmp = curr->next;
        curr->next = curr->next->next;
        tmp->next = NULL;
        delete tmp;
        c = 0;
    }
    return head->value;
}
