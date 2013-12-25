#pragma once

struct CycListElement
{
    int value;
    CycListElement *next;
};

void createNumberCycList(int n, CycListElement *head);

void printCycList(CycListElement *head);

int luckyNumberCycList(int n, CycListElement *head);
