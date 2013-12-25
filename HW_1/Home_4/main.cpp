#include <iostream>

int main()
{
    const int sum = 28;
    int mas[sum];
    for (int i = 0; i < 28; i++)
    {
        mas[i] = 0;
    }
    for (int i = 1; i < 1000; i++)
    {
        mas[i / 100 + i % 100 / 10 + i % 10]++;
    }
    unsigned int ticketsNimber = 1;
    for (int i = 1; i < sum; i++)
        ticketNumber += mas[i] * mas[i];
    printf("Number of lucky tickets = %u", ticketsNumber);
}

