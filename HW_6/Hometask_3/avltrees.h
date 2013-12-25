#pragma once


struct TreeNode
{
    int value;
    int height;
    TreeNode *parent;
    TreeNode *left;
    TreeNode *right;
};

struct Tree
{
    TreeNode *head;
};

void addValueTree(int value, Tree *mytree);

void putNode(int value, TreeNode **node, TreeNode *parent);

void deleteValueTree(int value, Tree *mytree);

bool doesTreeInclude(int value, Tree &mytree);

void printTreeLeftToRight(TreeNode *mytree);

void printTreeRightToLeft(TreeNode *mytree);

void printTreeSpecFormat(TreeNode *mytree);

TreeNode *createNewNode(int value);

void removeTree(TreeNode *mytree);

void littleLeftRotation(TreeNode *node, Tree *mytree);

void littleRightRotation(TreeNode *node, Tree *mytree);

void bigLeftRotation(TreeNode *node, Tree *mytree);

void bigRightRotation(TreeNode *node, Tree *mytree);

void balance(TreeNode *node, Tree *mytree);

void balanceNode(TreeNode *node, Tree *mytree);

int balanceFactor(TreeNode *node);

int height(TreeNode *node);

int updateHeight(TreeNode *node);
