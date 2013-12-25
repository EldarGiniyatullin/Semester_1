#include <iostream>
#include "double.h"

using namespace std;

enum Status {begin, first, operand, second, end, correct, incorrect};

void isIt()
{
    Status action = begin;
    char ch;
    bool firstOperation = false;
    switch (action)
    {
    case begin:
            cin.get(ch);
            if (ch == '(')
            {
              action = first;
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
            firstOperation = true;
            action = operand;
        }
        else if (isIt())
        {
            action = operand;
        }
        else
            action = incorrect;
        break;
    }



}

int main()
{

}

