#include <stdio.h>
#include "polishstack.h"

using namespace std;

void transfer(Stack &firstStack, Stack &secondStack)
{
    addSymbolStack(firstStack.first->symbol, secondStack);
    removeElementStack(firstStack);
}


int main()
{
    printf("Enter an expression ");
    Stack expStack;
    expStack.first = NULL;
    Stack operStack;
    operStack.first = NULL;
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
    while (expStack.first != NULL)
    {
        transfer(expStack, operStack);
    }
    printf("\nReverse Polish notation ");
    while (operStack.first != NULL)
    {
        printf("%c", operStack.first->symbol);
        removeElementStack(operStack);
    }
    delete operStack.first;
}
