#pragma once


struct TreeNode
{
    int value;
    TreeNode *parent;
    TreeNode *left;
    TreeNode *right;
};

struct Tree
{
    TreeNode *head;
};

void addValueTree(int value, Tree &mytree);

void deleteValueTree(int value, Tree &mytree);

bool doesTreeInclude(int value, Tree &mytree);

void printTreeLeftToRight(TreeNode *mytree);

void printTreeRightToLeft(TreeNode *mytree);

void printTreeSpecFormat(TreeNode *mytree);

TreeNode *createNewNode(int value);

void removeTree(TreeNode *mytree);
