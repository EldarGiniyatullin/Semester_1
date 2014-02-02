#include "codehuffman.h"
#include <fstream>
#include <iostream>

using std::cout;
using std::ios_base;
using std::ifstream;
using std::ofstream;

MyString createNew()
{
    MyString newString;
    newString.first = NULL;
    newString.last = NULL;
    return newString;
}

void addSymbolToHead(char ch, MyString *string)
{
    MySymbol *newSym = new MySymbol;
    newSym->symbol = ch;
    if (string->first)
    {
        newSym->next = string->first;
        string->first = newSym;
    }
    else
    {
        string->first = newSym;
        string->last = newSym;
        newSym->next = NULL;
    }
}

void numerification(TreeNode *newEl, MyString *codes, char ch)
{
    if (newEl->left)
    {
        numerification(newEl->left, codes, ch);
        numerification(newEl->right, codes, ch);
    }
    else
        addSymbolToHead(ch, &codes[(int)newEl->symbol]);
}

void buildTree(List &symbols, MyString *codes)
{
    if (!symbols.first->next)
    {
        addSymbolToHead('1', &codes[(int)symbols.first->symbol]);
    }
    else
    {
        while (symbols.first->next)
        {
            TreeNode *newEl = new TreeNode;
            newEl->left = symbols.first;
            newEl->right = symbols.first->next;
            newEl->next = NULL;
            newEl->symbol = '*';
            symbols.first = newEl->right->next;
            newEl->left->next = NULL;
            newEl->right->next = NULL;
            numerification(newEl->left, codes, '0');
            numerification(newEl->right, codes, '1');
            newEl->value = newEl->left->value + newEl->right->value;
            TreeNode **tmp = &(symbols.first);
            while ((*tmp) && newEl->value > (*tmp)->value)
                tmp = &((*tmp)->next);
            newEl->next = *tmp;
            *tmp = newEl;

        }
    }
}

void addSymbolList(char ch, List &symbols) //adds to list and makes it sorted
{
    TreeNode **tmp = &(symbols.first);
    while (*tmp && (*tmp)->symbol != ch)
        tmp = &((*tmp)->next);
    if (*tmp)
    {
        (*tmp)->value++;
        return;
    }
    else
    {
        TreeNode *newEl = new TreeNode;
        newEl->symbol = ch;
        newEl->right = NULL;
        newEl->left = NULL;
        newEl->value = 1;
        newEl->next = symbols.first;
        symbols.first = newEl;
    }
}

void copyString(MyString stringToCopy, MyString *string2)
{
    MySymbol *tmp = stringToCopy.first;
    MySymbol **tmp2 = &(string2->first);
    while(tmp)
    {
        MySymbol *newSym = new MySymbol;
        newSym->symbol = tmp->symbol;
        newSym->next = NULL;
        *tmp2 = newSym;
        string2->last = newSym;
        tmp = tmp->next;
        tmp2 = &((*tmp2)->next);
    }
}

void printTree(TreeNode* tree, ofstream &fout)
{
    if (tree->left)
    {
        fout << "(";
        printTree(tree->left, fout);
        printTree(tree->right, fout);
        fout << ")";
    }
    else fout << tree->symbol;
}

void deleteString(MyString &temp)
{
    MySymbol *tmp = temp.first;
    while (temp.first)
    {
        temp.first = temp.first->next;
        delete tmp;
        tmp = temp.first;
    }
    temp.last = NULL;
}

void printString(MyString string, ofstream &fout)
{
    MySymbol *tmp = string.first;
    while(tmp)
    {
        fout << tmp->symbol;
        tmp = tmp->next;
    }
}

void removeTree(TreeNode *node, TreeNode &tree)
{
    if (node->left != NULL)
        removeTree(node->left, tree);
    if (node->right != NULL)
        removeTree(node->right, tree);
    delete node;
}

void huffmanCoding(ifstream &fin)
{
    char ch = '\0';
    List symbols;
    symbols.first = NULL;
    fin.get(ch);
    while (!fin.eof())
    {
        if (ch != '\n')
            addSymbolList(ch, symbols);
        fin.get(ch);
    }
    fin.close();
    MyString codes[ascii];
    for (int i = 0; i < ascii; i++)
    {
        codes[i].first = NULL;
        codes[i].last = NULL;
    }
    buildTree(symbols, codes);
    fin.open("text.txt");
    ofstream fout("HuffmanCode.txt", ios_base::out | ios_base::trunc);
    printTree(symbols.first, fout);
    fout << "\n";
    while (!fin.eof())
    {
        fin.get(ch);
        if (ch != '\n')
        {
            printString(codes[(int)ch], fout);
        }
        else
        {
            fin.get(ch);
            if (!fin.eof())
            {
                fin.putback(ch);
                printString(codes[(int)ch], fout);
            }
        }
    }
    fin.close();
    fout.close();
    for (int i = 0; i < ascii; i++)
    {
        while (codes[i].first)
        {
            codes[i].last = codes[i].first;
            codes[i].first = codes[i].first->next;
            delete codes[i].last;
        }
    }
    removeTree(symbols.first, *symbols.first);
    symbols.first = NULL;
}
