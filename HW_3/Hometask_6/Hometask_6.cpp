#include <iostream>
#include "list.h"

enum Action {exitProgram, add, upSort, print};

int main()
{
    List myList;
    myList.first = NULL;
    Action act;
    while (act != -1)
    {
        cout << endl << endl;
        cout << "What would you like to do?" << endl;
        cout << "0 - exit" << endl;
        cout << "1 - add a value to list" << endl;
        cout << "2 - upsort list" << endl;
        cout << "3 - print list" << endl;
        cout << "So what? ";
        int val = 0;
        cin >> val;
        act = (Action)val;
        switch (act)
        {
        case exitProgram:
            while(myList.first != NULL)
            {
                removeValueList(myList.first->value, myList);
            }
            cout << "Goodbye";
            exit(0);
            break;
        case add: cout << "\nWhat value do you want to add? ";
            cin >> val;
            addValueList(val, myList);
            cout << endl;
            break;
        case upSort:
            sortUpInceptionList(myList);
            printList(myList);
            break;
        case print: printList(myList);
            break;
        default: cout << "\nIncorrect action\n";
            break;
        }
    }
}

