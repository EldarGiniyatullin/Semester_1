#include <iostream>

using namespace std;

int main()
{
    const int maxLen = 1000;
    char string1[maxLen];
    char string2[maxLen];
    cout << "Enter the lengths of s1 and s2: ";
    int string1Len;
    int string2Len;
    cin >> string1Len;
    cin >> string2Len;
    cout << "\nEnter s1: ";
    for (int i = 0; i <= string1Len - 1; i++)
    {
        cin >> string1[i];
    }
    cout << "\nEnter s2: ";
    for (int i = 0; i <= string2Len - 1; i++)
    {
        cin >> string2[i];
    }
    int includes = 0;
    for (int i = 0; i < string1Len; i++)
    {
        if (string1[i] == string2[0])
        {
            int j;
            for (j = 1; (j < string2Len) && (i + j < string1Len); j++)
            {
                if (string1[i + j] != string2[j])
                {
                    break;
                }
            }
            if (j == string2Len)
            {
                includes++;
            }
        }
    }
    cout << includes << " times";
}

