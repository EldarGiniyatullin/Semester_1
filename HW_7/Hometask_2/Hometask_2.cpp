#include <iostream>
#include "userstring.h"

using namespace std;

int main()
{
    cout  << "Enter ";
    MyString mystring = createNew();
    readString(mystring, ' ');
    deleteSymbol(mystring, 5);
    MyString mystring2 = clone(mystring);
    areEqual(mystring, mystring2);
    connect(mystring, mystring2);
    cout << stringLength(mystring);
    isEmpty(mystring);
    MyString mystring3 = includedString(mystring, 2, 4);
    char *array = charification(mystring);
    for (int i = 0; i < mystring.length; i++)
    {
        cout << array[i];
    }
    deleteString(mystring);
    deleteString(mystring2);
    deleteString(mystring3);
    delete[] array;
}

