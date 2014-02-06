#pragma once

using namespace std;

struct TreeNode
{
    TreeNode *right;
    TreeNode *left;
    char symbol;
};

void ifLetter(TreeNode *newTree, char ch);

TreeNode* buildTree(TreeNode *newTree, ifstream &fin);

void deleteTree(TreeNode *tree);

void readCode(ifstream &fin, TreeNode *tree, ofstream &fout);
