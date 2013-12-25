#include <iostream>
#include <fstream>
#include "userstring.h"

using namespace std;

int hashFunction(MyString &string)
{
    int hashCode = 0;
    MySymbol **tmp = &string.first;
    for (int i = 0; i < string.length; i++)
    {
        hashCode = (hashCode + (int)((*tmp)->symbol)) % 157;
        tmp = &((*tmp)->next);
    }
    return hashCode;
}

int middleValue(MyString &string, int hashValue)
{
    return ((hashValue + 157 - ((int)string.first->symbol - ((int)string.first->symbol / 157) * 157)) % 157);
}

int main()
{
    fstream fin("text.txt");
    if (!fin.is_open())
    {
        cout << "Couldn\'t open file text.txt";
    }
    else
    {
        cout << "Enter the word (end it by pressing Tab, please): ";
        MyString word = createNewString();
        readString(word, '\t');
        MyString fileText = createNewString();
        readString(fileText, word.length, fin);
        if (fileText.length != word.length)
            cout << "\nThe text is shorter than the word";
        else
        {
            int howMany = 0;
            MySymbol *tmp = fileText.first;
            char ch = '\0';
            int hashValue = hashFunction(fileText);
            int wordValue = hashFunction(word);
            int tempValue = 0;
            while (!fin.eof())
            {
                if (hashValue == wordValue && areEqual(word, fileText))
                    howMany++;
                tempValue = middleValue(fileText, hashValue);

                fin.get(ch);
                if (fileText.first)
                {
                    fileText.last->next = createNewSymbol(ch);
                    fileText.last = fileText.last->next;
                    if (tmp)
                    {
                        tmp = tmp->next;
                    }
                    else
                        tmp = fileText.last;
                    delete fileText.first;
                    fileText.first = tmp;
                }
                else
                {
                    fileText.last = createNewSymbol(ch);
                    fileText.first = fileText.last;
                }
                if (fileText.last)
                {
                    hashValue = (tempValue + (int)fileText.last->symbol) % 157;
                }
                else
                {
                    hashValue = tempValue % 157;
                }
            }
            cout << "The text includes the word " << howMany << " times";
        }
        deleteString(word);
        deleteString(fileText);
    }
}

