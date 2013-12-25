#pragma once

struct ListElement
{
    int townNumber;
    int cost;
    ListElement *next;
};

struct List
{
    ListElement *first;
};

ListElement **findMinimal(List myList);

void addElementSorted(List &myList, int cost, int town);

void addElement(List &myList, int cost, int town);

void deleteListElement(ListElement** elem, List &myList);

void deleteList(List &myList);

void dijkstra(int **roads, int numberOfTowns, int town1);
