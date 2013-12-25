#include <iostream>

using namespace std;

int main()
{
    cout << "Enter the length of string ";
    int strLen;
    cin >> strLen;
    cout << "\nEnter the string: ";
    char *str;
    for (int i = 0; i < strLen; i++)
        cin >> str[i];
    bool isPalindrome = true;
    for (int i = 0; i <= strLen / 2 - 1; i++)
    {
        if (str[i] != str[strLen - i - 1])
        {
            isPalindrome = false;
            break;
        }
    }
    if (isPalindrome)
    {
        cout << "\nPalindrome";
    }
    else cout << "\nIs not palindrome";
}

