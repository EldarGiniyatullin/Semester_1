#include <iostream>
#include "trees.h"

using std::cin;
using std::cout;

TreeNode* createNewNode(int value)
{
    TreeNode *newNode = new TreeNode;
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;
    return newNode;
}

void addValueTree(int value, Tree &mytree)
{
    if (mytree.head == NULL)
    {
        TreeNode *curr = createNewNode(value);
        mytree.head = curr;
        curr->parent = NULL;
    }
    else
    {
        TreeNode *p = mytree.head;
        bool isAdded = false;
        while (!isAdded)
        {
            if (p->value == value)
            {
                isAdded = true;
            }
            else if (p->value > value)
            {
                if (p->left != NULL)
                {
                    p = p->left;
                }
                else
                {
                    TreeNode *curr = createNewNode(value);
                    p->left = curr;
                    curr->parent = p;
                    isAdded = true;
                }
            }
            else if (p->value < value)
            {
                if (p->right != NULL)
                {
                    p = p->right;
                }
                else
                {
                    TreeNode *curr = createNewNode(value);
                    p->right = curr;
                    curr->parent = p;
                    isAdded = true;
                }
            }
        }
    }
}

enum Orient {left, right};

void deleteOrient(Tree *mytree, TreeNode *&temp, Orient leftOrRight)
{
    TreeNode *node = NULL;
    if (leftOrRight == 0)
        node = temp->left;
    else node = temp->right;
    if (temp != mytree->head)
    {
        if (temp->parent->left == temp)
        {
           temp->parent->left = node;
        }
        else
        {
           temp->parent->right = node;
        }
    }
    else if (temp == mytree->head)
    {
        mytree->head = node;
    }
    if (node)
    {
        node->parent = temp->parent;
        node = node->parent;
    }
    delete temp;
    temp = NULL;
}

void deleteValueTree(int value, Tree &mytree)
{
    TreeNode *tmp = mytree.head;
    bool isRemoved = false;
    while (tmp != NULL && !isRemoved)
    {
        if (tmp->value > value)
        {
            tmp = tmp->left;
        }
        else if (tmp->value < value)
        {
            tmp = tmp->right;
        }
        else if (tmp->value == value)
        {
            if (tmp->left != NULL && tmp->right == NULL)
            {
                deleteOrient(&mytree, tmp, left);
                isRemoved = true;
            }
            else if (tmp->left == NULL && tmp->right != NULL)
            {
                deleteOrient(&mytree, tmp, right);
                isRemoved = true;
            }
            else if (tmp->left != NULL && tmp->right != NULL)
            {
                TreeNode *max = tmp->right;
                while (max->left != NULL)
                {
                    max = max->left;
                }
                tmp->value = max->value;
                if (max != tmp->right)
                {
                    if (max->right != NULL)
                    {
                        max->parent->left = max->right;
                    }
                    else
                    {
                        max->parent->left = NULL;
                    }
                }
                else
                {
                    if (max->right != NULL)
                    {
                        tmp->right = max->right;
                    }
                    else
                    {
                        tmp->right = NULL;
                    }
                }
                delete max;
                max = NULL;
                isRemoved = true;
            }
            else if (tmp->left == NULL && tmp->right == NULL)
            {
                deleteOrient(&mytree, tmp, left);
                isRemoved = true;
            }
        }
    }
}

bool doesTreeInclude(int value, Tree &mytree)
{
    TreeNode *p = mytree.head;
    while (p != NULL)
    {
        if (p->value > value)
        {
            p = p->left;
        }
        else if (p->value < value)
        {
            p = p->right;
        }
        else if (p->value == value)
        {
            return true;
        }
    }
    return false;
}

void printTreeLeftToRight(TreeNode *mytree)
{
    if (mytree != NULL)
    {
        if (mytree->left != NULL)
            printTreeLeftToRight(mytree->left);
        cout << mytree->value;
        if (mytree->right != NULL)
            printTreeLeftToRight (mytree->right);
    }
    else
        cout << "Empty tree";
}

void printTreeRightToLeft(TreeNode *mytree)
{
    if (mytree != NULL)
    {
        if (mytree->right != NULL)
            printTreeRightToLeft (mytree->right);
        cout << mytree->value;
        if (mytree->left != NULL)
            printTreeRightToLeft (mytree->left);
    }
    else
        cout << "Empty tree";
}

void printTreeSpecFormat(TreeNode *mytree)
{
    if (mytree != NULL)
    {
        cout << "(";
        cout << (mytree->value) << " ";
        if (mytree->left != NULL)
        {
            printTreeSpecFormat(mytree->left);
            cout << " ";
        }
        else if (mytree->left == NULL)
            cout << "null ";
        if (mytree->right != NULL)
        {
            printTreeSpecFormat(mytree->right);
            cout << " ";
        }
        else if (mytree->right == NULL)
            cout << "null";
        cout << ")";
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
