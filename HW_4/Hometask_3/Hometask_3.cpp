#include <stdio.h>
#include "polishstack.h"

using namespace std;

int main()
{
    printf("Enter an infix-Polish-notation-reformed expression ");
    Stack wareStack;
    wareStack.first = NULL;
    char consoleSymbol;
    bool isZero = false;
    bool isRight = false;
    while ((consoleSymbol = getchar()) != '\n' && !isZero && !isRight)
    {
        switch(consoleSymbol)
        {
            case '+':
            if (wareStack.first == NULL || wareStack.first->next == NULL)
            {
                isRight = true;
                break;
            }
            else
            {
                wareStack.first->next->value = wareStack.first->next->value + wareStack.first->value;
                removeElementStack(wareStack);
                break;
            }
            case '-':
            if (wareStack.first == NULL || wareStack.first->next == NULL)
            {
                isRight = true;
                break;
            }
            else
            {
                wareStack.first->next->value = wareStack.first->next->value - wareStack.first->value;
                removeElementStack(wareStack);
                break;
            }
            case '*':
            if (wareStack.first == NULL || wareStack.first->next == NULL)
            {
                isRight = true;
                break;
            }
            else
            {
                wareStack.first->next->value = wareStack.first->next->value * wareStack.first->value;
                removeElementStack(wareStack);
                break;
            }
            case '/':
            if (wareStack.first == NULL || wareStack.first->next == NULL)
            {
                isRight = true;
                break;
            }
            else
            {
                if (wareStack.first->value == 0)
                {
                    printf("\nDividing by zero!");
                    isZero = true;
                    break;
                }
                else
                {
                    wareStack.first->next->value = wareStack.first->next->value / wareStack.first->value;
                    removeElementStack(wareStack);
                    break;
                }
            }
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
                addValueStack((int)consoleSymbol - '0', wareStack);
                break;
        }
    }
    if (wareStack.first->next != NULL)
    {
        isRight = true;
    }
    if (isRight && !isZero)
    {
         printf("\nInvalid transcription");
    }
    if (!isZero && !isRight)
    {
        printf("\n=%d", wareStack.first->value);
    }
    delete wareStack.first;
}
