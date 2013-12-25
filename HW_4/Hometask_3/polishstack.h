#pragma once

struct StackElement
{
    int value;
    char symbol;
    StackElement *next;
};

struct Stack
{
    StackElement *first;
};

void addSymbolStack(char i, Stack &myStack);

void addValueStack(int i, Stack &myStack);

void removeElementStack(Stack &myStack);
