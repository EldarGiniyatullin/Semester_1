#pragma once

struct TreeNode
{
    int value;
    char action;
    TreeNode *parent;
    TreeNode *left;
    TreeNode *right;
};

struct Tree
{
    TreeNode *head;
};

void printSumTree(TreeNode *mytree, Tree &sumtree);

TreeNode *createNewNode(char ch);

TreeNode *createNewNode(int value);

void removeTree(TreeNode *mytree);

int sumResult(TreeNode *mytree);
