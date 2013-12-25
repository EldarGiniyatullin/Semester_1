#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    char ch;
    ifstream fin("program.txt");
    if (!fin.is_open())
            cout << "Couldn\'t open file!";
    else
    {
        cout << "Comments:" << endl;
        bool isSlashFirst = false;
        bool isSlashSecond = false;
        bool isStar = false;
        while (!fin.eof())
        {
            fin.get(ch);
            if (ch == '/')
            {
                if (!isSlashFirst)
                {
                    isSlashFirst = true;
                }
                else
                {
                    if (ch == '/')
                    {
                        cout << "//";
                        while (ch != '\n')
                        {
                            fin.get(ch);
                            cout << ch;
                        }
                        isSlashFirst = false;
                    }
                    else
                    {
                        isSlashFirst = false;
                    }
                }
            }
            else if (ch == '*' && isSlashFirst)
            {
                isSlashFirst = false;
                isStar = true;
                while (!isSlashSecond && !fin.eof())
                {
                    fin.get(ch);
                    if (ch == '*')
                    {
                        fin.get(ch);
                        if (ch == '/')
                            isSlashSecond = true;
                    }
                }
                isSlashSecond = false;
                isStar = false;
            }
            else if (ch == '"')
            {
                fin.get(ch);
                while (ch != '"' && !fin.eof())
                {
                    fin.get(ch);
                }
            }
        }
    }
    fin.close();
    return 0;
}
