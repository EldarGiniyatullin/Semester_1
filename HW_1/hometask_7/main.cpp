#include <iostream>

using namespace std;

int main()
{
    int mas[28];
    for (int i = 0; i < 28; i++)
    {
        mas[i] = 0;
    }
    for (int i = 1; i < 1000; i++)
    {
        mas[i / 100 + i % 100 / 10 + i % 10]++;
    }
    unsigned int otvet = 1;
    for (int i = 1; i < 28; i++)
        otvet+=mas[i]*mas[i];
    printf("Number of lucky tickets = %u", otvet);
}

