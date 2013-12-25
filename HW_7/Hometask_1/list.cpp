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
        int num = 1;
        while(curr)
        {
            cout << num << " " << curr->value << "\n";
            curr = curr->next;
            num++;
        }
    }
    delete[] curr;
}


void addValueList(int num, int value, List &mylist)
{

}
