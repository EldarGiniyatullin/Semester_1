#include <iostream>
#include "taskmodule.h"

#define maxlength 32767

using std::cout;

ListElement **findMinimal(List myList)
{
    if (myList.first == NULL)
        return NULL;
    else
    {
        ListElement **curr = &(myList.first);
        ListElement **tmp = &(myList.first);
        int min = maxlength;
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
    bool isAdded = false;
    while (*curr)
    {
        if ((*curr)->townNumber == town)
        {
            if (!isAdded)
            {
                if (cost < (*curr)->cost)
                    (*curr)->cost = cost;
                delete newEl;
            }
            else
            {
                ListElement *tmp = *curr;
                *curr = (*curr)->next;
                delete tmp;
            }
            return;
        }
        else if (((*curr)->townNumber != town && (*curr)->cost > cost) && !isAdded)
        {
            newEl->next = *curr;
            *curr = newEl;
            isAdded = true;
            if (!(*curr)->next)
                return;
        }
        curr = &((*curr)->next);
    }
    if (!(*curr) && !isAdded)
    {
        newEl->next = *curr;
        *curr = newEl;
    }
}

void addElement(List &myList, int cost, int town)
{
    ListElement **tmp = &(myList.first);
    while (*tmp)
    {
        tmp = &((*tmp)->next);
    }
    ListElement *newEl = new ListElement;
    newEl->cost = cost;
    newEl->townNumber = town;
    *tmp = newEl;
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

void dijkstra(int **roads, int numberOfTowns, int town1)
{
    bool *isOccupied = new bool[numberOfTowns];
    for (int i = 0; i < numberOfTowns; i++)
        isOccupied[i] = false;
    int **ways = new int*[numberOfTowns];
    for (int i = 0; i < numberOfTowns; i++)
    {
        ways[i] = new int[numberOfTowns + 1];
        for (int j = 0; j < numberOfTowns; j++)
            ways[i][j] = 0;
        ways[i][numberOfTowns] = maxlength;
    }
    List tempTowns;
    tempTowns.first = NULL;
    addElementSorted(tempTowns, 0, town1);
    ListElement *minimal = tempTowns.first;
    ways[0][0] = 1;
    while (minimal)
    {
        for (int i = 0; i < numberOfTowns; i++)
        {
            if (!isOccupied[i] && (roads[minimal->townNumber - 1][i] > 0) && ((minimal->cost + roads[minimal->townNumber - 1][i]) < ways[i][numberOfTowns]))
            {
                ways[i][numberOfTowns] = minimal->cost + roads[minimal->townNumber - 1][i];
                bool isLast = false;
                for (int j = 0; j < numberOfTowns; j++)
                {
                    ways[i][j] = ways[minimal->townNumber - 1][j];
                    if (ways[i][j] == 0 && !isLast)
                    {
                        isLast = true;
                        ways[i][j] = i + 1;
                    }
                }
                addElementSorted(tempTowns, ways[i][numberOfTowns], i + 1);
            }
        }
        isOccupied[minimal->townNumber - 1] = true;
        cout << "Town " << minimal->townNumber << " (" << minimal->cost << ") Way: 1";
        for (int i = 1; (i < numberOfTowns) && (ways[minimal->townNumber - 1][i] != 0); i++)
        {
            cout << " - " << ways[minimal->townNumber - 1][i];
        }
        cout << "\n";
        minimal = minimal->next;
    }
    delete[] isOccupied;
    for (int i = 0; i <= numberOfTowns; i++)
    {
        delete[] ways[i];
    }
    delete[] ways;
    deleteList(tempTowns);
}
