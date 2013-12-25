#include <iostream>
#include "double.h"

using namespace std;

enum Status {begin, first, operand, second, end, correct, incorrect};

bool isIt()
{
    Status action = begin;
    char ch;
    bool firstOperation = false;
    bool isBreak = false;
    while(true)
    {
        switch (action)
        {
        case begin:
            cin.get(ch);
            if (ch == '(')
            {
                isBreak = true;
                cin.get(ch);
                if (ch == ' ')
                    action = first;
                else
                    action = incorrect;
            }
            else
            {
                cin.putback(ch);
                action = first;
            }
            break;
        case first:
            if (isDouble())
            {
                firstOperation = false;
                action = operand;
            }
            else if (isIt())
            {
                firstOperation = true;
                action = operand;
            }
            else
                action = incorrect;
            break;
        case operand:
            if (firstOperation)
            {
                cin.get(ch);
                if (ch != ' ')
                {
                    action = incorrect;
                }
            }
            if (action != incorrect)
            {
                cin.get(ch);
                if (isOperand(ch))
                {
                    cin.get(ch);
                    if (ch != ' ')
                    {
                        action = incorrect;
                    }
                    else
                        action = second;
                }
                else
                    action = incorrect;
            }
            break;
        case second:
            if (isDouble())
            {
                firstOperation = false;
                action = end;
            }
            else if (isIt)
            {
                firstOperation = true;
                action = end;
            }
            else
            {
                action = incorrect;
            }
            break;
        case end:
            if (firstOperation)
            {
                cin.get(ch);
                if (ch != ' ')
                    action = incorrect;
            }
            if (isBreak)
            {
                cin.get(ch);
                if (ch == ')')
                {
                    action = correct;
                }
                else
                    action = incorrect;
            }
            if (!isBreak && action != incorrect)
                action = correct;
            break;
        case correct:
            return true;
            break;
        default:
            return false;
            break;
        }
    }
}

int main()
{
    cout << "Enter the operation: ";
    isIt() ? cout << "\nYes" : cout << "\nNo";
}

