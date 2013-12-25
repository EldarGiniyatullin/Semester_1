#include <iostream>
#include <fstream>
#include "sumtrees.h"

using namespace std;

TreeNode* treefication(ifstream &fin)
{
    char c;
    fin >> c;
    fin >> c;
    TreeNode *newNode = createNewNode(c);
    fin >> c;
    if (c == '(')
    {
        fin.putback(c);
        newNode->left = treefication(fin);
    }
    else
    {
        fin.putback(c);
        int num1 = 0;
        fin >> num1;
        TreeNode *leftNode = createNewNode(num1);
        newNode->left = leftNode;
    }
    fin >> c;
    if (c == '(')
    {
        fin.putback(c);
        newNode->right = treefication(fin);
    }
    else
    {
        fin.putback(c);
        int num2 = 0;
        fin >> num2;
        TreeNode *rightNode = createNewNode(num2);
        newNode->right = rightNode;
    }
    fin >> c;
    return newNode;
}


int main()
{
    ifstream fin("sum.txt");
    if (!fin.is_open())
            cout << "Couldn\'t open file!";
    else
    {
        Tree sumtree;
        sumtree.head = treefication(fin);
        printSumTree(sumtree.head, sumtree);
        int sum = 0;
        sum = sumResult(sumtree.head);
        cout << " = " << sum;
        removeTree(sumtree.head);
        sumtree.head = NULL;
    }
    fin.close();
}

