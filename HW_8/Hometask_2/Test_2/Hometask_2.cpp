#include <fstream>
#include <iostream>

using namespace std;

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

ListElement **findMinimal(List myList)
{
    if (myList.first == NULL)
        return NULL;
    else
    {
        ListElement **curr = &(myList.first);
        ListElement **tmp = &(myList.first);
        int min = 32767;
        while (*tmp)
        {
            if ((*tmp)->cost < min)
            {
                curr = tmp;
                min = (*curr)->cost;
            }
            tmp = &((*tmp)->next);
        }
        return curr;
    }
}

void addElementSorted(List &myList, int cost, int town)
{
    ListElement *newEl = new ListElement;
    newEl->cost = cost;
    newEl->townNumber = town;
    ListElement **curr = &(myList.first);
    while (*curr)
    {
        if (((*curr)->cost > cost) || !(*curr))
        {
            newEl->next = *curr;
            *curr = newEl;
            return;
        }
        curr = &((*curr)->next);
    }
    newEl->next = *curr;
    *curr = newEl;
}

void deleteListElement(ListElement** elem, List &myList)
{
    ListElement *tmp = *elem;
    *elem = (*elem)->next;
    delete tmp;
}

void deleteList(List &myList)
{
    ListElement *tmp = myList.first;
    while (myList.first)
    {
        tmp = myList.first;
        myList.first = myList.first->next;
        delete tmp;
    }
}

void addElement(List &myList, int cost, int town)
{
    ListElement **curr = &(myList.first);
    while (*curr)
    {
        if ((*curr)->townNumber == town)
        {
            if (cost < (*curr)->cost)
                (*curr)->cost = cost;
            return;
        }
        curr = &((*curr)->next);
    }
    if (!(*curr))
    {
        ListElement *newEl = new ListElement;
        newEl->cost = cost;
        newEl->townNumber = town;
        *curr = newEl;
        newEl->next = NULL;
        curr = &(myList.first);
    }
}

int Dijkstra(int **roads, int numberOfTowns, int town1, int town2)
{
    bool *isOccupied = new bool[numberOfTowns];
    for (int i = 0; i < numberOfTowns; i++)
        isOccupied[i] = false;
    int *costs = new int[numberOfTowns];
    for (int i = 0; i < numberOfTowns; i++)
        costs[i] = 32767;
    List tempTowns;
    tempTowns.first = NULL;
    addElement(tempTowns, 0, town1);
    ListElement **minimal= &(tempTowns.first);
    while (*minimal)
    {
        for (int i = 0; i < numberOfTowns; i++)
        {
            if (!isOccupied[i] && (roads[(*minimal)->townNumber - 1][i] > 0) && (((*minimal)->cost + roads[(*minimal)->townNumber - 1][i]) < costs[i]))
            {
                costs[i] = (*minimal)->cost + roads[(*minimal)->townNumber - 1][i];
                addElement(tempTowns, costs[i], i + 1);
            }
        }
        isOccupied[(*minimal)->townNumber - 1] = true;
        deleteListElement(minimal, tempTowns);
        minimal = findMinimal(tempTowns);
    }
    delete[] isOccupied;
    delete[] costs;
    deleteList(tempTowns);
    return costs[town2 - 1];
}

int main()
{
    ifstream fin("towns.txt");
    if (!fin.is_open())
    {
        cout << "Couldn\'t open file";
    }
    else
    {
        int numberOfTowns = 0;
        int numberOfRoads = 0;
        fin >> numberOfTowns >> numberOfRoads;
        int **roads = new int*[numberOfTowns];
        for (int i = 0; i < numberOfTowns; i++)
        {
            roads[i] = new int[numberOfTowns];
            for (int j = 0; j < numberOfTowns; j++)
                roads[i][j] = 0;
        }
        int town1 = 0;
        int town2 = 0;
        int length = 0;
        for (int i = 0; i < numberOfRoads; i++)
        {
            fin >> town1 >> town2 >> length;
            roads[town1 - 1][town2 - 1] = length;
            roads[town2 - 1][town1 - 1] = length;
        }
        List towns;
        towns.first = NULL;
        for (int i = 1; i < numberOfTowns; i++)
        {
            addElementSorted(towns, Dijkstra(roads, numberOfTowns, 1, i + 1), i + 1);
        }
        ListElement *curr = towns.first;
        cout  << "(Danzig, 01.09.1939) - ";
        while(curr->next)
        {
            cout << (curr->townNumber) << " - ";
            curr = curr->next;
        }
        cout << "(Kock, 05.10.1939)";
        for (int i = 0; i < numberOfTowns; i++)
        {
            delete[] roads[i];
        }
        delete[] roads;
        deleteList(towns);
    }
}

