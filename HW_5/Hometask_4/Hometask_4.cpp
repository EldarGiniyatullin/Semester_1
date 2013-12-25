#include <iostream>
#include <fstream>
#include "userstring.h"
#include "list.h"
#include "myhashfunction.h"

using namespace std;

int myHashFunc1(MyString& string)
{
    int hashCode = 0;
    MySymbol **tmp = &string.first;
    for (int i = 0; i < string.length; i++)
    {
        hashCode = (hashCode + 31 * ((int)((*tmp)->symbol))) % 1000;
        tmp = &((*tmp)->next);
    }
    return hashCode;
}

int myHashFunc2(MyString& string)
{
    int hashCode = 0;
    MySymbol **tmp = &string.first;
    for (int i = 0; i < string.length; i++)
    {
        hashCode = (hashCode + 31 * ((int)((*tmp)->symbol))) % 1000;
        tmp = &((*tmp)->next);
    }
    return hashCode;
}

enum Input {exitProgram, addData, findNumber, findName, saveCurrentData};

int main()
{
    fstream fin;
    fin.open("data.txt");
    List savedData = createNewList();
    List addedData = createNewList();
    HashData hashName = createHashData(&myHashFunc1);
    HashData hashNumber = createHashData(&myHashFunc2);
    if (fin.is_open())
    {
        while (!fin.eof())
        {
            MyString word = createNewString();
            readWord(word, no, fin);
            if (fin.eof())
            {
                deleteString(word);
                break;
            }
            MyString number = createNewString();
            readString(number, '\n', fin);
            addValueList(word, number, savedData);
            hashing(word, savedData.first, hashName);
            hashing(number, savedData.first, hashNumber);
            deleteString(word);
            deleteString(number);
        }
    }
    fin.close();
    fin.open("data.txt", ios_base::out | ios_base::app);
    int action;
    Element *temp = NULL;
    MyString tmp = createNewString();
    MyString tmp2 = createNewString();
    char ch;
    while(true)
    {
        cout << "0 - exit \n1 - add information (name & number)\n2 - find number\n3 - find name\n4 - save to file\nWhat do you want to do?\n";
        cin >> action;
        switch((Input)action)
        {
        case 0:
        {
            deleteList(addedData);
            deleteList(savedData);
            deleteHashData(hashName);
            deleteHashData(hashNumber);
            fin.close();
            cout << "Goodbye\n";
            return 0;
            break;
        }
        case 1:
        {
            cout << "Enter the number ";
            cin.get(ch);
            readString(tmp, '\n');
            cout << "\nEnter the name ";
            readWord(tmp2, no);
            addValueList(tmp2, tmp, addedData);
            hashing(tmp2, addedData.first, hashName);
            hashing(tmp, addedData.first, hashNumber);
            printHashTable(hashName);
            printHashTable(hashNumber);
            deleteString(tmp);
            deleteString(tmp2);
            break;
        }
        case 2:
        {
            cout << "Enter the name ";
            cin.get(ch);
            readString(tmp, '\n');
            temp = hashName.hashTable[hashName.hashFunction(tmp)];
            while (temp != NULL)
            {
                if (areEqual(temp->element->name, tmp))
                {
                    break;
                }
                else
                    temp = temp->next;
            }
            if (temp != NULL)
            {
                cout << "The number is ";
                printString(temp->element->number);
            }
            else
                cout << "There's no number for the person\n";
            cout << endl;
            deleteString(tmp);
            temp = NULL;
            break;
        }
        case 3:
            cout << "Enter the number ";
            cin.get(ch);
            readString(tmp, '\n');
            temp = hashNumber.hashTable[hashNumber.hashFunction(tmp)];
            while (temp != NULL)
            {
                if (areEqual(temp->element->number, tmp))
                {
                    break;
                }
                else
                    temp = temp->next;
            }
            if (temp != NULL)
            {
                cout << "The name is ";
                printString(temp->element->name);
            }
            else
                cout << "There's no name you wanna find\n";
            cout << endl;
            deleteString(tmp);
            temp = NULL;
            break;
        case 4:
        {
            ListElement *current = addedData.first;
            while (current != NULL)
            {
                printString(current->name, fin);
                fin << " ";
                printString(current->number, fin);
                fin << "\n";
                current = current->next;
            }
            if (savedData.first)
            {
                savedData.last->next = addedData.first;
            }
            savedData.last = addedData.last;
            addedData.first = NULL;
            addedData.last = NULL;
            cout << "\nInformation successfully saved\n";
            break;
        }
        default:
            {
                cout << "\nIncorrect action\n";
                break;
            }
        }
    }
}
