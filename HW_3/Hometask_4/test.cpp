#include <iostream>
#include <stdlib.h>
#include <list.h>

using namespace std;

int main()
{
    List mylist;
    mylist.first = new ListEl;
    mylist->first->next = nullptr;
    ListEl *tmp = list->first;
    for (int i = 0; i < 5; i++)
    {
        ListEl *newEl = new ListEl;
        newEl->value = i;
        newEl->next = nullptr;
        tmp->next = newEl;
        tmp = tmp->next;
    }
    cout << "Hello\n";
    printList(mylist);
}

