#pragma once
#include <fstream>

using std::ofstream;
using std::fstream;

struct MySymbol
{
    char symbol;
    MySymbol *next;
};

struct MyString
{
    int length;
    MySymbol *first;
    MySymbol *last;
};

enum Status{yes, no};

MyString createNewString();

MySymbol *createNewSymbol(char ch);

void readString(MyString &string, int number, std::fstream &fin);

void readString(MyString &string, char limit);

void readString(MyString &string, char limit, fstream &fin);

void deleteSymbol(MyString &string, int number);

void deleteSymbol(MySymbol &symbol, MySymbol *previous);

MyString clone(MyString string);

void connect(MyString &leftString, MyString rightString);

bool areEqual(MyString string1, MyString string2);

int stringLength(MyString string);

bool isEmpty(MyString string);

MyString includedString(MyString mainString, int first, int last);

char *charification(MyString string);

void deleteString(MyString &string);

void readWord(MyString &word, Status isCapitalEqualSmall);

void readWord(MyString &word, Status isCapitalEqualSmall, std::fstream &fin);

void printString(MyString &string);

void printString(MyString &string, ofstream &fout);
