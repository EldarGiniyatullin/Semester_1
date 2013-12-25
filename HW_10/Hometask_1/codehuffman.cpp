#include "codehuffman.h"
#include <fstream>

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

void addSymbol(char ch, MyString *string)
{
    MySymbol *newSym = new MySymbol;
    newSym->next = NULL;
    newSym->symbol = ch;
    if (string->first)
    {
        string->last->next = newSym;
        string->last = newSym;
    }
    else
    {
        string->first = newSym;
        string->last = newSym;
    }
}

MyString buildTree(List &symbols)
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
            newEl->value = newEl->left->value + newEl->right->value;
            TreeNode **tmp = &(symbols.first);
            while ((*tmp) && newEl->value > (*tmp)->value)
                tmp = &((*tmp)->next);
            newEl->next = *tmp;
            *tmp = newEl;
        }
}

void addSymbolList(char ch, List &symbols) //adds to list and make it sorted
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
    fout << "(" << tree->symbol << " ";
    if (tree->left)
    {
        if (tree->left->left)
            printTree(tree->left, fout);
        else fout << tree->left->symbol;
    }
    fout << " ";
    if (tree->right)
    {
        if (tree->right->left)
            printTree(tree->right, fout);
        else fout << tree->right->symbol;
    }
    fout << ")";
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

void codification(TreeNode *node, MyString *codes, MyString temp)
{
    if (node->symbol == '*')
    {
        MyString *temp2 = new MyString;
        temp2->first = NULL;
        temp2->last = NULL;
        copyString(temp, temp2);
        addSymbol('0', temp2);
        codification(node->left, codes, *temp2);
        temp2->last->symbol = '1';
        codification(node->right, codes, *temp2);
        deleteString(*temp2);
        delete temp2;
    }
    else
    {
        if (!temp.first)
            addSymbol('0', &temp);
        copyString(temp, &codes[(int)node->symbol]);
    }
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
    buildTree(symbols);
    fin.open("text2.txt");
    ofstream fout("HuffmanCode.txt", ios_base::out | ios_base::trunc);
    printTree(symbols.first, fout);
    fout << "\n";
    MyString codes[ascii];
    for (int i = 0; i < ascii; i++)
    {
        codes[i].first = NULL;
        codes[i].last = NULL;
    }
    MyString *temp = new MyString;
    temp->first = NULL;
    temp->last = NULL;
    codification(symbols.first, codes, *temp);
    delete temp;
    while (!fin.eof())
    {
        fin.get(ch);
        if (ch != '\n')
        {
            printString(codes[(int)ch], fout);
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
    delete symbols.first;
    symbols.first = NULL;
}
