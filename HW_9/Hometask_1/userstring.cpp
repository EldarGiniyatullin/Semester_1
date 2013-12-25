#include <iostream>
#include <cctype>
#include "userstring.h"
#include <fstream>

using std::cin;
using std::cout;
using std::ifstream;
using std::ofstream;
using std::fstream;


MyString createNewString()
{
    MyString string;
    string.first = NULL;
    string.length = 0;
    return string;
}

MySymbol *createNewSymbol(char ch)
{
    MySymbol *symbol = new MySymbol;
    symbol->symbol = ch;
    symbol->next = NULL;
    return symbol;
}

void readWord(MyString &word, Status isCapitalEqualSmall)
{
    char ch;
    cin.get(ch);
    word.first = createNewSymbol(ch);
    MySymbol *tmp = word.first;
    word.length++;
    cin.get(ch);
    while ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
    {
        if (isCapitalEqualSmall == no)
            ch = (char)tolower(ch);
        tmp->next = createNewSymbol(ch);
        tmp = tmp->next;
        word.length++;
        cin.get(ch);
    }
}

void readWord(MyString &word, Status isCapitalEqualSmall, fstream &fin)
{
    char symbol;
    fin.get(symbol);
    word.first = createNewSymbol(symbol);
    MySymbol *tmp = word.first;
    word.length++;
    fin.get(symbol);
    while ((symbol >= 'a' && symbol <= 'z') || (symbol >= 'A' && symbol <= 'Z'))
    {
        if (isCapitalEqualSmall == no)
            symbol = (char)tolower(symbol);
        tmp->next = createNewSymbol(symbol);
        tmp = tmp->next;
        word.length++;
        fin.get(symbol);
    }
}

void readString(MyString &string, int number)
{
    char ch;
    cin.get(ch);
    string.first = createNewSymbol(ch);
    MySymbol *tmp = string.first;
    string.length++;
    number--;
    while (number != 0)
    {
        cin.get (ch);
        tmp->next = createNewSymbol(ch);
        tmp = tmp->next;
        string.length++;
        number--;
    }
}

void readString(MyString &string, char limit)
{
    char ch;
    //string.first = createNewSymbol(ch);
    MySymbol **tmp = &(string.first);
    //string.length++;
    cin.get(ch);
    while (ch != limit)
    {
        *tmp = createNewSymbol(ch);
        tmp = &((*tmp)->next);
        string.length++;
        cin.get(ch);
    }
}

void readString(MyString &string, char limit, fstream &fin)
{
    char ch;
    //string.first = createNewSymbol(ch);
    MySymbol **tmp = &(string.first);
    //string.length++;
    fin.get(ch);
    while (ch != limit)
    {
        *tmp = createNewSymbol(ch);
        tmp = &((*tmp)->next);
        string.length++;
        fin.get(ch);
    }
}

void deleteSymbol(MySymbol *symbol, MySymbol *previous)
{
    if (symbol != NULL)
    {
        previous->next = symbol->next;
        delete symbol;
    }
}

void deleteSymbol(MyString &string, int number)
{
    if (number <= string.length)
    {
        string.length--;
        MySymbol *curr = string.first;
        if (number == 1)
        {
            string.first = curr->next;
            delete curr;
        }
        else
        {
            number--;
            while(number != 1)
            {
                curr = curr->next;
                number--;
            }
            deleteSymbol(curr->next, curr);
        }
    }
}

MyString clone(MyString string)
{
    MyString newString = createNewString();
    MySymbol *curr = string.first;
    newString.length = string.length;
    if (newString.length > 0)
    {
        newString.first = createNewSymbol(string.first->symbol);
        curr = curr->next;
        MySymbol *newCurr = newString.first;
        while (curr != NULL)
        {
            newCurr->next = createNewSymbol(curr->symbol);
            curr = curr->next;
            newCurr = newCurr->next;
        }
    }
    return newString;
}

void connect(MyString &leftString, MyString rightString)
{
    leftString.length += rightString.length;
    MySymbol *tmp = leftString.first;
    MyString rightClone = clone(rightString);
    if (!isEmpty(leftString))
    {
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = rightClone.first;
    }
    else
        leftString.first = rightClone.first;
    rightClone.first = NULL;
}

bool areEqual(MyString string1, MyString string2)
{
    if (string1.length == string2.length)
    {
        MySymbol *curr1 = string1.first;
        MySymbol *curr2 = string2.first;
        while (curr1 != NULL && curr1->symbol == curr2->symbol)
        {
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        return (curr1 == NULL) ? true : false;
    }
    else return false;
}

int stringLength(MyString string)
{
    return string.length;
}

bool isEmpty(MyString string)
{
    return string.first == NULL ? true : false;
}

MyString includedString(MyString mainString, int first, int last)
{
    MyString newString = createNewString();
    if (first <= last)
    {
        MySymbol *curr = mainString.first;
        last -= first;
        first--;
        while (first != 0)
        {
            curr = curr->next;
            first--;
        }
        newString.length = last + 1;
        newString.first = createNewSymbol(curr->symbol);
        curr = curr->next;
        MySymbol *newCurr = newString.first;
        while (last != 0 && curr != NULL)
        {
            last--;
            newCurr->next = createNewSymbol(curr->symbol);
            curr = curr->next;
            newCurr = newCurr->next;
        }
    }
    return newString;
}

char* charification(MyString string)
{
    char *array = new char[string.length];
    MySymbol *curr = string.first;
    int i = 0;
    while (curr != NULL)
    {
        array[i] = curr->symbol;
        curr = curr->next;
        i++;
    }
    return array;
}

void deleteString(MyString &string)
{
    MySymbol *tmp = string.first;
    while (string.first != NULL)
    {
        string.first = string.first->next;
        delete tmp;
        tmp = string.first;
    }
    string.length = 0;
}

void printString(MyString &string)
{
    MySymbol *curr = string.first;
    for (int i = 0; i < string.length; i++)
    {
        cout << curr->symbol;
        curr = curr->next;
    }
}

void printString(MyString &string, ofstream &fout)
{
    MySymbol *curr = string.first;
    for (int i = 0; i < string.length; i++)
    {
        fout.put(curr->symbol);
        curr = curr->next;
    }
}
