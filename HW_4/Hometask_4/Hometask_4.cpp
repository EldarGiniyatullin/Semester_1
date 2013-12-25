#include <stdio.h>
#include "polishstack.h"

using namespace std;

void transfer(Stack &firstStack, Stack &secondStack)
{
    addSymbolStack(firstStack.first->symbol, secondStack);
    secondStack.first->value = firstStack.first->value;
    removeElementStack(firstStack);
}

void specialTransfer(Stack &firstStack, Stack &secondStack)
{
    addSymbolStack(firstStack.first->symbol, secondStack);
    if (secondStack.first->symbol >= '0' && secondStack.first->symbol <= '9')
        secondStack.first->value = secondStack.first->symbol - '0';
    removeElementStack(firstStack);
}

void prefixPolishNotation(Stack &expStack, Stack &operStack)
{
    char consoleSymbol;
    while ((consoleSymbol = getchar()) != '\n')
    {
        switch(consoleSymbol)
        {
        case '+':
        case '-':
            if (operStack.first == NULL || operStack.first->symbol == '(')
            {
                addSymbolStack(consoleSymbol, operStack);
            }
            else if (operStack.first->symbol == '+' || operStack.first->symbol == '-' || operStack.first->symbol == '*' || operStack.first->symbol == '/')
            {
                transfer(operStack, expStack);
                addSymbolStack(consoleSymbol, operStack);
            }
            break;
        case '*':
        case '/':
            if (operStack.first == NULL || operStack.first->symbol == '(' || operStack.first->symbol == '+' || operStack.first->symbol == '-')
            {
                addSymbolStack(consoleSymbol, operStack);
            }
            else if (operStack.first->symbol == '*' ||  operStack.first->symbol == '/')
            {
                transfer(operStack, expStack);
                addSymbolStack(consoleSymbol, operStack);
            }
            break;
        case '(':
            addSymbolStack(consoleSymbol, operStack);
            break;
        case ')':
            while (operStack.first->symbol != '(')
            {
                 transfer(operStack, expStack);
            }
            removeElementStack(operStack);
            if (operStack.first != NULL)
            {
                transfer(operStack, expStack);
            }
            break;
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            addSymbolStack(consoleSymbol, expStack);
            break;
        }
    }
    while (operStack.first != NULL)
    {
        transfer(operStack, expStack);
    }
    while (expStack.first != NULL)
    {
        specialTransfer(expStack, operStack);
    }
}

void calculatePrefixfPolishNotation(Stack &operStack)
{
    Stack expStack;
    expStack.first = NULL;
    StackElement *tmp = operStack.first;
    bool isZero = false;
    while (!isZero && tmp->next != NULL)
    {
        if (tmp->next->symbol == '+' || tmp->next->symbol ==  '-' || tmp->next->symbol ==  '*' || tmp->next->symbol ==  '/')
        {
            switch(tmp->next->symbol)
            {
            case '+':
                tmp->value = expStack.first->value + tmp->value;
                break;
            case '-':
                tmp->value = expStack.first->value - tmp->value;
                break;
            case '*':
                tmp->value = expStack.first->value * tmp->value;
                break;
            case '/':
                if (tmp->value == 0)
                {
                    printf("\nDividing by zero!");
                    isZero = true;
                    break;
                }
                else
                {
                    tmp->value = expStack.first->value / tmp->value;
                    break;
                }
            }
            removeElementStack(expStack);
            tmp->next->value = tmp->value;
            tmp = tmp->next;
            removeElementStack(operStack);
        }
        else
        {
            tmp = tmp->next;
            transfer(operStack, expStack);
        }
    }
    if (!isZero)
    {
        printf("\n=%d", operStack.first->value);
    }
    delete expStack.first;
}

int main()
{
    printf("Enter an expression ");
    Stack expStack;
    expStack.first = NULL;
    Stack operStack;
    operStack.first = NULL;
    prefixPolishNotation(expStack, operStack);
    calculatePrefixfPolishNotation(operStack);
    delete expStack.first;
    delete operStack.first;
}
