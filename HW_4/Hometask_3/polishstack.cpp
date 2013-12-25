#include "polishstack.h"
#include <stdio.h>

using namespace std;

void printStack(Stack myStack)
{
    printf("\n");
    StackElement *curr = myStack.first;
    if (myStack.first == NULL)
    {
        printf("No elements in the list");
    }
    else
    {
        while(curr)
        {
            printf("%c", curr->value);
            curr = curr->next;
        }
    }
    delete[] curr;
}

void removeElementStack(Stack &myStack)
{
    if (myStack.first != NULL)
    {
        StackElement *p = myStack.first;
        myStack.first = myStack.first->next;
        p->next = NULL;
        delete p;
    }
}


void addSymbolStack(char i, Stack &myStack)
{
    StackElement *newEl = new StackElement;
    newEl->symbol = i;
    if (myStack.first == NULL)
    {
        myStack.first = newEl;
        newEl->next = NULL;
    }
    else if (myStack.first != NULL)
    {
        StackElement *tmp = myStack.first;
        myStack.first = newEl;
        newEl->next = tmp;
    }
}

void addValueStack(int i, Stack &myStack)
{
    StackElement *newEl = new StackElement;
    newEl->value = i;
    if (myStack.first == NULL)
    {
        myStack.first = newEl;
        newEl->next = NULL;
    }
    else if (myStack.first != NULL)
    {
        StackElement *tmp = myStack.first;
        myStack.first = newEl;
        newEl->next = tmp;
    }
}
