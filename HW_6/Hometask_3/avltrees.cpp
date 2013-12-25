#include <iostream>
#include "avltrees.h"

using std::cin;
using std::cout;

enum Orient {left, right};

TreeNode* createNewNode(int value)
{
    TreeNode *newNode = new TreeNode;
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;
    newNode->height = 0;
    return newNode;
}

void addValueTree(int value, Tree *mytree)
{
    if (mytree->head == NULL)
    {
        TreeNode *curr = createNewNode(value);
        mytree->head = curr;
        curr->height = 1;
    }
    else
    {
        TreeNode *tmp = mytree->head;
        bool isAdded = false;
        bool isAddedYet = false;
        TreeNode* tmp2 = NULL;
        while (!isAdded && !isAddedYet)
        {
            if (tmp->value == value)
            {
                isAddedYet = true;
            }
            else if (tmp->value > value)
            {
                if (tmp->left != NULL)
                {
                    tmp = tmp->left;
                }
                else
                {
                    putNode(value, &(tmp->left), tmp);
                    tmp2 = tmp;
                    while (tmp2 != NULL)
                    {
                        tmp2->height = updateHeight(tmp2);
                        tmp2 = tmp2->parent;
                    }
                    isAdded = true;
                }
            }
            else if (tmp->value < value)
            {
                if (tmp->right != NULL)
                {
                    tmp = tmp->right;
                }
                else
                {
                    putNode(value, &(tmp->right), tmp);
                    tmp2 = tmp;
                    while (tmp2 != NULL)
                    {
                        tmp2->height = updateHeight(tmp2);
                        tmp2 = tmp2->parent;
                    }
                    isAdded = true;
                }
            }
        }
        if (!isAddedYet)
        {
            balance(tmp, mytree);
        }
    }
}

void putNode(int value, TreeNode** node, TreeNode *parent)
{
    TreeNode *curr = createNewNode(value);
    *node = curr;
    curr->parent = parent;
    curr->height = 1;
}

void deleteOrient(Tree *mytree, TreeNode *&temp, Orient leftOrRight)
{
    TreeNode *node = NULL;
    TreeNode *tmp = *&temp;
    if (leftOrRight == left)
        node = tmp->left;
    else node = tmp->right;
    if (tmp != mytree->head)
    {
        if (tmp->parent->left == tmp)
        {
           tmp->parent->left = node;
        }
        else
        {
           tmp->parent->right = node;
        }
    }
    else if (tmp == mytree->head)
    {
        mytree->head = node;
    }
    if (node)
    {
        node->parent = tmp->parent;
        node = node->parent;
    }
    while (node != NULL)
    {
        node->height = updateHeight(node);
        node = node->parent;
    }
    delete temp;
    temp = NULL;
}

void deleteValueTree(int value, Tree *mytree)
{
    TreeNode *tmp = mytree->head;
    bool isRemoved = false;
    TreeNode *deletedPlace = NULL;
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
                deletedPlace = tmp->parent;
                deleteOrient(mytree, tmp, left);
                isRemoved = true;
            }
            else if (tmp->left == NULL && tmp->right != NULL)
            {
                deletedPlace = tmp->parent;
                deleteOrient(mytree, tmp, right);
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
                {
                    deletedPlace = max->parent;
                    if (max != tmp->right)
                    {
                        if (max->right != NULL)
                        {
                            max->parent->left = max->right;
                            max->right->parent = max->parent;
                        }
                        else
                        {
                            max->parent->left = NULL;
                        }
                        max->parent->height = updateHeight(max->parent);
                    }
                    else
                    {
                        if (max->right != NULL)
                        {
                            tmp->right = max->right;
                            max->right->parent = tmp;
                        }
                        else
                        {
                            tmp->right = NULL;
                        }
                        tmp->height = updateHeight(tmp);
                    }
                    delete max;
                    max = NULL;
                    isRemoved = true;
                }
            }
            else if (tmp->left == NULL && tmp->right == NULL)
            {
                deletedPlace = tmp->parent;
                deleteOrient(mytree, tmp, left);
                isRemoved = true;
            }
        }
    }
    if (isRemoved)
    {
        balance(deletedPlace, mytree);
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
        cout << mytree->value << " ";
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
        cout << mytree->value << " ";
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

void littleLeftRotation(TreeNode *node, Tree *mytree)
{
    TreeNode *tmp = node->right;
    if (node->parent)
    {
        if (node->parent->left == node)
            node->parent->left = tmp;
        else
            node->parent->right = tmp;
    }
    else
    {
        mytree->head = node->right;
    }
    node->right = tmp->left;
    if (node->right)
        node->right->parent = node;
    tmp->parent = node->parent;
    node->parent = tmp;
    tmp->left = node;
    node->height--;
    tmp->height++;
    node = tmp;
}

void littleRightRotation(TreeNode *node, Tree *mytree)
{

    TreeNode *tmp = node->left;
    if (node->parent)
    {
        if (node->parent->left == node)
            node->parent->left = tmp;
        else
            node->parent->right = tmp;
    }
    else
    {
        mytree->head = node->left;
    }
    node->left = tmp->right;
    if (node->left)
        node->left->parent = node;
    tmp->parent = node->parent;
    node->parent = tmp;
    tmp->right = node;
    node->height--;
    tmp->height++;
    node = tmp;
}
void bigRightRotation(TreeNode *node, Tree *mytree)
{
    littleLeftRotation(node->left, mytree);
    littleRightRotation(node, mytree);
}
void bigLeftRotation(TreeNode *node, Tree *mytree)
{
    littleRightRotation(node->right, mytree);
    littleLeftRotation(node, mytree);
}

void balance(TreeNode *node, Tree *mytree)
{
    while (node != NULL)
    {
        balanceNode(node, mytree);
        TreeNode *tmp = node;
        if (node->left)
            node->left->height = updateHeight(node->left);
        if (node->right)
            node->right->height = updateHeight(node->right);
        while (tmp != NULL)
        {
            tmp->height = updateHeight(tmp);
            tmp = tmp->parent;
        }
        node = node->parent;
    }
}

void balanceNode(TreeNode *node, Tree *mytree)
{
    if (balanceFactor(node) == 2)
    {
        if (balanceFactor(node->right) >= 0)
        {
            littleLeftRotation(node, mytree);
        }
        else
        {
            bigLeftRotation(node, mytree);
        }
    }
    else if (balanceFactor(node) == -2)
    {
        if (balanceFactor(node->left) <= 0)
        {
            littleRightRotation(node, mytree);
        }
        else
        {
            bigRightRotation(node, mytree);
        }
    }
}

int balanceFactor(TreeNode *node)
{
    return (height(node->right) - height(node->left));
}

int height(TreeNode *node)
{
    return node ? node->height : 0;
}

int updateHeight(TreeNode *node)
{
        int heightLeft = height(node->left);
        int heightRight = height(node->right);
        return (heightLeft >= heightRight ? heightLeft + 1 : heightRight + 1);
}
