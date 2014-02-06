#include <iostream>
#include <fstream>
#include "huffmanDecrypting.h"

using namespace std;

int main()
{
    ifstream fin("HuffmanCode.txt");
    if (!fin.is_open())
    {
        cout << "Couldn\'t open file \"HuffmanCode.txt\"";
    }
    else
    {
        char ch = '\0';
        TreeNode *tree = new TreeNode;
        fin.get(ch);
        buildTree(tree, fin);
        fin.get(ch);
        ofstream fout("output.txt", ios_base::out | ios_base::trunc);
        readCode(fin, tree, fout);
        cout << "The result added to \"output.txt\"";
        deleteTree(tree);
        delete tree;
        fin.close();
        fout.close();
    }
}
