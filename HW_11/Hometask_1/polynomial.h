#pragma once


struct PolynomialElement
{
    int degree;
    int coef;
    PolynomialElement *next;
};

struct Polynomial
{
    PolynomialElement *first;
    PolynomialElement *last;
};


Polynomial createNewPol();

PolynomialElement *createMon(int coef, int degree);

void printPol(Polynomial myPol);

Polynomial sumPols(Polynomial firstPol, Polynomial secondPol);

double polValue(Polynomial myPol, int argument);

bool arePolsEqual(Polynomial firstPol, Polynomial secondPol);

void deletePol(Polynomial &myPol);
