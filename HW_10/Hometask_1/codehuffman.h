#pragma once

#include <fstream>

const int ascii = 128;

using std::ifstream;
using std::ofstream;

struct TreeNode
{
    int value;
    TreeNode *right;
    TreeNode *left;
    TreeNode *next;
    char symbol;
};

struct List
{
    TreeNode *first;
};

struct MySymbol
{
    char symbol;
    MySymbol *next;
};

struct MyString
{
    MySymbol *first;
    MySymbol *last;
};

MyString createNew();

void addSymbol(char ch, MyString *string);

MyString buildTree(List &symbols);

void addSymbolList(char ch, List &symbols); //adds to list and make it sorted

void copyString(MyString stringToCopy, MyString *string2);

void printTree(TreeNode* tree, ofstream &fout);

void codification(TreeNode *node, MyString *codes, MyString temp);

void printString(MyString string, ofstream &fout);

void removeTree(TreeNode *node, TreeNode &tree);

void huffmanCoding(ifstream &fin);
