#include <iostream>
#include <fstream>
#include "huffmandecrypting.h"

using namespace std;

void ifLetter(TreeNode *newTree, char ch)
{
    newTree->symbol = ch;
    newTree->left = NULL;
    newTree->right = NULL;
}

TreeNode* buildTree(TreeNode *newTree, ifstream &fin)
{
    char ch = '\0';
    TreeNode *newLeft = new TreeNode;
    TreeNode *newRight = new TreeNode;
    newTree->left = newLeft;
    newTree->right = newRight;
    fin.get(ch);
    if (ch == '(')
    {
        buildTree(newTree->left, fin);
    }
    else
        ifLetter(newTree->left, ch);
    fin.get(ch);
    if (ch == '(')
    {
        buildTree(newTree->right, fin);
    }
    else
        ifLetter(newTree->right, ch);
    fin.get(ch);
}

void deleteTree(TreeNode *tree)
{
    if (tree->left)
        deleteTree(tree->left);
    if (tree->right)
        deleteTree(tree->right);
    delete tree;
}

void readCode(ifstream &fin, TreeNode *tree, ofstream &fout)
{
    char ch = '\0';
    while (ch != '\n' && !fin.eof())
    {
        TreeNode *tmp = tree;
        while (!fin.eof())
        {
            fin.get(ch);
            if (tmp->left)
            {
                if (ch == '0')
                {
                    tmp = tmp->left;
                }
                else if (ch == '1')
                {
                    tmp = tmp->right;
                }
            }
            else
            {
                if (!fin.eof())
                {
                    fin.putback(ch);
                    fout << tmp->symbol;
                    break;
                }
                else
                {
                    fout << tmp->symbol;
                    return;
                }
            }
        }
    }
}
