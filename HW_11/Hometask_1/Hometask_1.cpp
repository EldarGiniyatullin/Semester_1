#include <iostream>
#include "polynomial.h"
#include <iomanip>

using namespace std;

enum Action {exitProgram = 0, equals, value, add};

int main()
{
    int monom = 0;
    int tmpDegree = 0;
    int tmpCoef = 0;
    cout << "Enter the first polynomial\nNumber of monomials: ";
    cin >> monom;
    Polynomial firstPol =  createNewPol();
    cout << "\nEnter the monomials\' coefs (from maximal to minimal) and degrees:\n";
    for (int i = 0; i < monom; i++)
    {
        cin >> tmpCoef >> tmpDegree;
        PolynomialElement *tmpMon = createMon(tmpCoef, tmpDegree);
        if (i != 0)
        {
            firstPol.last->next = tmpMon;
            firstPol.last = firstPol.last->next;
        }
        else
        {
            firstPol.first = tmpMon;
            firstPol.last = firstPol.first;
        }
    }
    cout << "Enter the second polynomial\nNumber of monomials: ";
    cin >> monom;
    Polynomial secondPol =  createNewPol();
    cout << "\nEnter the monomials\' coefs (from maximal to minimal) and degrees:\n";
    for (int i = 0; i < monom; i++)
    {
        cin  >> tmpCoef >> tmpDegree;
        PolynomialElement *tmpMon = createMon(tmpCoef, tmpDegree);
        if (i != 0)
        {
            secondPol.last->next = tmpMon;
            secondPol.last = secondPol.last->next;
        }
        else
        {
            secondPol.first = tmpMon;
            secondPol.last = secondPol.first;
        }
    }
    int act = 0;
    while(true)
    {
        cout << "\nWhat to do?\n0 - exit\n1 - verify, are the polynomials equal\n2 - calculate the value of polynomial\n3 - calculate the sum of the polynomials\n";
        cin >> act;
        switch ((Action)act)
        {
        case exitProgram:
            cout << "\nGoodbye";
            deletePol(firstPol);
            deletePol(secondPol);
            return 0;
            break;
        case equals:
        {
            bool areEqual = arePolsEqual(firstPol, secondPol);
            areEqual ? cout << "\nYes" : cout << "\nNo";
            break;
        }
        case value:
        {
            cout << "\nEnter the argument\'s value ";
            int argument = 0;
            cin >> argument;
            double polVal = polValue(firstPol, argument);
            cout << "The first polynomial = " << setprecision(6) << (float)polVal;
            polVal = polValue(secondPol, argument);
            cout << "\nThe second polynomial = " << setprecision(6) << (float)polVal << endl;
            break;
        }
        case add:
        {
            Polynomial thirdPol = createNewPol();
            thirdPol = sumPols(firstPol, secondPol);
            cout << "\n";
            printPol(thirdPol);
            deletePol(thirdPol);
            break;
        }
        default:
            cout << "\nIncorrect action";
            break;
        }
    }
}
