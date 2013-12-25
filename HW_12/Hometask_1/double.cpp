#include "double.h"
#include <iostream>

enum Status{incorrect = -1, firstSign, requiredNumericAfterSign, numericsBeforeDotOrE, requiredNumericAfterDot, numericsAfterDot, degreeE, signAfterE, endingNumerics, correct};

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

bool isDouble()
{
    int lexemeBeginning = 1;
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
            lexemeBeginning++;
        }
        else if (isDigit(ch))
        {
            action = numericsBeforeDotOrE;
            lexemeBeginning++;
        }
        else
            action = incorrect;
            break;
        case requiredNumericAfterSign:
            if (isDigit(ch))
            {
                action = numericsBeforeDotOrE;
                lexemeBeginning++;
            }
            else
                action = incorrect;
            break;
        case numericsBeforeDotOrE:
            cin.get(ch);
            if (isDigit(ch))
            {
                lexemeBeginning++;
            }
            else if (ch == '.')
            {
                lexemeBeginning++;
                action = requiredNumericAfterDot;
            }
            else if (ch == 'E')
            {
                lexemeBeginning++;
                action = degreeE;
            }
            else if (isEnding(ch))
                action = correct;
            else
                action = incorrect;
            break;
        case requiredNumericAfterDot:
            cin.get(ch);
            if (isDigit(ch))
            {
                action = numericsAfterDot;
                lexemeBeginning++;
            }
            else
                action = incorrect;
            break;
        case numericsAfterDot:
            cin.get(ch);
            if (isDigit(ch))
            {
                lexemeBeginning++;
            }
            else if (ch == 'E')
            {
                lexemeBeginning++;
                action = degreeE;
            }
            else if (isEnding(ch))
                action = correct;
            else
                action = incorrect;
            break;
        case degreeE:
            cin.get(ch);
            if (isSign(ch))
            {
                action = signAfterE;
                lexemeBeginning++;
            }
            else if (isDigit(ch))
            {
                action = endingNumerics;
                lexemeBeginning++;
            }
            else
                action = incorrect;
            break;
        case signAfterE:
            cin.get(ch);
            if (isDigit(ch))
            {
                action = endingNumerics;
                lexemeBeginning++;
            }
            else
                action = incorrect;
            break;
        case endingNumerics:
            cin.get(ch);
            if (isDigit(ch))
                lexemeBeginning++;
            else if (isEnding(ch))
                action = correct;
            else
                action = incorrect;
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
