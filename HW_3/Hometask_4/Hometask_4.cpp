#include <iostream>
#include "list.h"

using namespace std;

enum Action {stopProgram = -1, exitProgram, addValue, removeValue, print};

int main()
{
    List mylist;
    mylist.first = NULL;
    Action act;
    while (act != -1)
    {
        cout << endl << endl;
        cout << "What would you like to do?" << endl;
        cout << "0 - exit" << endl;
        cout << "1 - add a value to sorted list" << endl;
        cout << "2 - remove a value from sorted list" << endl;
        cout << "3 - print list" << endl;
        cout << "So what? ";
        int val = 0;
        cin >> val;
        act = (Action)val;
        switch (act)
        {
        case exitProgram:
            while(mylist.first != NULL)
            {
                removeValueList(mylist.first->value, mylist);
            }
            cout << "Goodbye";
            exit(0);
            break;
        case addValue: cout << "\nWhat value do you want to add? ";
            cin >> val;
            addValueList(val, mylist);
            cout << endl;
            break;
        case removeValue:
            cout << "\nWhat value do you want to delete? ";
            cin >> val;
            removeValueList(val, mylist);
            cout << endl;
            break;
        case print: printList(mylist);
            break;
        default: cout << "\nIncorrect action\n";
            break;
        }
    }
}

