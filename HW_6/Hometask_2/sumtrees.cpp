#include <iostream>
#include "sumtrees.h"

using namespace std;

TreeNode *createNewNode(int value)
{
    TreeNode *newNode = new TreeNode;
    newNode->value = value;
    newNode->action = '0';
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;
    return newNode;
}

TreeNode *createNewNode(char ch)
{
    TreeNode *newNode = new TreeNode;
    newNode->value = 0;
    newNode->action = ch;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;
    return newNode;
}

void printSumTree(TreeNode *mytree, Tree &sumtree)
{
    if (mytree != NULL)
    {
        if (mytree->left != NULL)
        {
            if (mytree != sumtree.head)
                cout << "(";
            printSumTree(mytree->left, sumtree);
        }
        if (mytree->action == '0')
        {
            cout << mytree->value;
        }
        else
        {
            cout << mytree->action;
        }
        if (mytree->right != NULL)
        {
            printSumTree(mytree->right, sumtree);
            if (mytree != sumtree.head)
                cout << ")";
        }
    }
    else
        cout << "Empty tree";
}

void removeTree(TreeNode *mytree)
{
    if (mytree != NULL)
    {
        if (mytree->right != NULL)
            removeTree(mytree->right);
        if (mytree->left != NULL)
            removeTree(mytree->left);
        delete mytree;
    }
}

int sumResult(TreeNode *mytree)
{
    int num1 = 0;
    int num2 = 0;
    int result = 0;
    if (mytree->left != NULL)
    {
        if (mytree->left->action != '0')
            num1 = sumResult(mytree->left);
        else
            num1 = mytree->left->value;
    }
    if (mytree->right != NULL)
    {
        if (mytree->right->action != '0')
            num2 = sumResult(mytree->right);
        else
            num2 = mytree->right->value;
    }
    switch (mytree->action)
    {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            result = num1 / num2;
            break;
        default:
            break;
    }
    mytree->action = '0';
    return result;
}
