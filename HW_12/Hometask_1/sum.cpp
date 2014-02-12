#include <iostream>
#include "sum.h"
#include "double.h"

using std::cin;

enum Status {sum, operand, correct, incorrect};

bool isSum(bool noBreak)
{
    Status action = sum;
    char ch = '\0';
    while(true)
    {
        switch (action)
        {
        case sum:
            cin.get(ch);
            if (ch == '(')
            {
                if (isSum(false))
                {
                    cin.get(ch);
                    action = (ch == ')') ? operand : incorrect;
                }
            }
            else
            {
                cin.putback(ch);
                noBreak ? (action = isDouble(true) ? operand : incorrect) : (action = isDouble(false) ? operand : incorrect);
            }
            break;
        case operand:
            cin.get(ch);
            if (isEnding(ch) && noBreak)
                action = correct;
            else if (ch == ')')
            {
                cin.putback(ch);
                action = correct;
            }
            else if (isOperand(ch))
                action = sum;
            else
                action = incorrect;
            break;
        case correct:
            return true;
        default:
            return false;
        }
    }
}

