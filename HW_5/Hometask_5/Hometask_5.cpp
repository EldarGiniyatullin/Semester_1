#include <iostream>

using std::cin;
using std::cout;

const char *word[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fivteen", "sixteen", "seventeen", "eighteen", "nineteen"};
const char *word1[] = {"twenty", "thirty", "fourty", "fivety", "sixty", "seventy", "eighty", "ninety"};
const char *word3[] = {"hundred", "thousand", "and", "teen", "ty", "zero"};

void printNumberLessThan1000(int number)
{
    if (number / 100 != 0)
    {
        cout << word[number / 100] << " " << word3[0] << " ";
    }
    if (number / 100 != 0 && number % 100 != 0)
        cout << word3[2] << " ";
    if (number % 100 != 0)
    {
        int temp = number % 100;
        if (number % 100 > 19)
            cout << word1[(temp / 10) - 2] << " " << word[number % 10] << " ";
        else
            cout << word[temp % 100] << " ";
    }
}

int main()
{
    int number = 0;
    cout << "Enter the number: ";
    cin >> number;
    if (number / 1000 > 0)
    {
        printNumberLessThan1000(number / 1000);
        cout << word3[1] << " " << word3[2] << " ";
    }
    if (number % 1000 == 0)
    {
        cout << word3[5];
    }
    else
        printNumberLessThan1000(number % 1000);
}
