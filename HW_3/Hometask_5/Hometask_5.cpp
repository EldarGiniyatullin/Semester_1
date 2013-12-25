#include <iostream>
#include "cycliclist.h"

using namespace std;

int main()
{
    cout << "Enter the number of defenders: ";
    int soldiersNumber = 0;
    cin >> soldiersNumber;
    CycListElement *head = new CycListElement;
    createNumberCycList(soldiersNumber, head);
    cout << "\nEach ";
    int round = 0;
    cin >> round;
    cout << " will die";
    cout << "\n" << ((round == 1) ? soldiersNumber : luckyNumberCycList(round, head)) << " soldier is lucky";
    delete head;
}
