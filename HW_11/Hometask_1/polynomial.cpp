#include "polynomial.h"
#include <iostream>
#include <math.h>

using std::cout;

Polynomial createNewPol()
{
    Polynomial pol;
    pol.first = NULL;
    pol.last = NULL;
    return pol;
}

PolynomialElement *createMon(int coef, int degree)
{
    PolynomialElement *newEl = new PolynomialElement;
    newEl->next = NULL;
    newEl->degree = degree;
    newEl->coef = coef;
    return newEl;
}

double degreeOfNumber(int base, int index)
{
    if (index == 0)
        return 1;
    else if (index > 0)
    {
        unsigned int power = 1;
        for (int i = 1; i <= index; i++)
        {
            power *= base;
        }
        return (double)power;
    }
    else if (index < 0)
    {
        double power = 1;
        for (int i = 0; i >= index; i--)
        {
            power /= base;
        }
        return power;
    }
}

void printPol(Polynomial myPol)
{
    PolynomialElement *tmp = myPol.first;
    while(tmp)
    {
        if (tmp->coef < 0)
        {
            cout << " - ";
        }
        else if (tmp != myPol.first)
        {
            cout << " + ";
        }
        cout << abs(tmp->coef) << "^" << tmp->degree;
        tmp = tmp->next;
    }
}

Polynomial sumPols(Polynomial firstPol, Polynomial secondPol)
{
    Polynomial newPol = createNewPol();
    PolynomialElement *tmp1 = firstPol.first;
    PolynomialElement *tmp2 = secondPol.first;
    while (tmp1 || tmp2)
    {
        PolynomialElement *newEl = new PolynomialElement;
        newEl->next = NULL;
        if (tmp1)
        {
            if (tmp2 && tmp1->degree == tmp2->degree)
            {
                newEl->degree = tmp1->degree;
                newEl->coef = tmp1->coef + tmp2->coef;
                tmp2 = tmp2->next;
                tmp1 = tmp1->next;
            }
            else if (!tmp2 || tmp1->degree > tmp2->degree)
            {
                newEl->degree = tmp1->degree;
                newEl->coef = tmp1->coef;
                tmp1 = tmp1->next;
            }
            else if (tmp2 && tmp1->degree < tmp2->degree)
            {
                newEl->degree = tmp2->degree;
                newEl->coef = tmp2->coef;
                tmp2 = tmp2->next;
            }
        }
        else if (tmp2)
        {
            newEl->degree = tmp2->degree;
            newEl->coef = tmp2->coef;
            tmp2 = tmp2->next;
        }
        if (newEl->coef != 0)
        {
            if (newPol.first)
            {
                newPol.last->next = newEl;
                newPol.last = newPol.last->next;
            }
            else
            {
                newPol.first = newEl;
                newPol.last = newPol.first;
            }
        }
        else if (!tmp1 && !tmp2)
        {
            delete newEl;
        }
    }
    return newPol;
}

double polValue(Polynomial myPol, int argument)
{
    double value = 0;
    PolynomialElement *tmp = myPol.first;
    while (tmp)
    {
        value = value + tmp->coef * degreeOfNumber(argument, tmp->degree);
        tmp = tmp->next;
    }
    return value;
}

bool arePolsEqual(Polynomial firstPol, Polynomial secondPol)
{
    PolynomialElement *tmp1 = firstPol.first;
    PolynomialElement *tmp2 = secondPol.first;
    while (tmp1 && tmp2)
    {
        if (tmp1->degree == tmp2->degree && tmp1->coef == tmp2->coef)
        {
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        }
        else
        {
            return false;
        }
    }
    return (!tmp1 && !tmp2);
}

void deletePol(Polynomial &myPol)
{
    PolynomialElement *tmp = myPol.first;
    while(tmp)
    {
        myPol.first = myPol.first->next;
        delete tmp;
        tmp = myPol.first;
    }
    myPol.last = NULL;
}
