#include "double.h"
#include <iostream>

enum Status{incorrect = -1, firstSign, requiredNumericAfterSign, numericsBeforeDotOrE, requiredNumericAfterDot, numericsAfterDot, degreeE, signAfterE, endingNumerics, correct};

using namespace std;

bool isOperand(char ch)
{
    return (isSign(ch) || ch == '*' || ch == '/') ? true : false;
}

bool isSign(char ch)
{
    return (ch == '+' || ch == '-') ? true : false;
}

bool isDigit(char ch)
{
    return (ch >= '0' && ch <= '9') ? true : false;
}

bool isE(char ch)
{
    return (ch == 'E') ? true : false;
}

bool isEnding(char ch)
{
    return (ch == ' ' || ch == '\n' || ch == '\t' || ch == '\0') ? true : false;
}

bool isDouble(bool noBreak)
{
    char ch;
    Status action = firstSign;
    while(true)
    {
        switch (action)
        {
        case firstSign:
        cin.get(ch);
        if (isSign(ch))
        {
            action = requiredNumericAfterSign;
        }
        else if (isDigit(ch))
        {
            action = numericsBeforeDotOrE;
        }
        else
            action = incorrect;
            break;
        case requiredNumericAfterSign:
            if (isDigit(ch))
            {
                action = numericsBeforeDotOrE;
            }
            else
                action = incorrect;
            break;
        case numericsBeforeDotOrE:
            cin.get(ch);
            if (ch == '.')
            {
                action = requiredNumericAfterDot;
            }
            else if (ch == 'E')
            {
                action = degreeE;
            }
            else if (isOperand(ch) || (ch == ')' && !noBreak))
            {
                cin.putback(ch);
                action = correct;
            }
            else if (isEnding(ch))
                action = correct;
            else if (!(isDigit(ch)))
                action = incorrect;
            break;
        case requiredNumericAfterDot:
            cin.get(ch);
            if (isDigit(ch))
            {
                action = numericsAfterDot;
            }
            else
                action = incorrect;
            break;
        case numericsAfterDot:
            cin.get(ch);
            if (ch == 'E')
            {
                action = degreeE;
            }
            else if (isOperand(ch) || (ch == ')' && !noBreak))
            {
                cin.putback(ch);
                action = correct;
            }
            else if (isEnding(ch))
                action = correct;
            else if (!isDigit(ch))
                action = incorrect;
            break;
        case degreeE:
            cin.get(ch);
            if (isSign(ch))
            {
                action = signAfterE;
            }
            else if (isDigit(ch))
            {
                action = endingNumerics;
            }
            else
                action = incorrect;
            break;
        case signAfterE:
            cin.get(ch);
            if (isDigit(ch))
            {
                action = endingNumerics;
            }
            else
                action = incorrect;
            break;
        case endingNumerics:
            cin.get(ch);
            if (isEnding(ch))
                action = correct;
            else if (isOperand(ch) || (ch == ')' && !noBreak))
            {
                cin.putback(ch);
                action = correct;
            }
            else if (!isDigit(ch))
                action = incorrect;
            break;
        case correct:
            return true;
        default:
            return false;
        }
    }
}
