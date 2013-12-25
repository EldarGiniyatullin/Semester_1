#include <fstream>
#include <iostream>
#include "taskmodule.h"

#define maxlength 32767

using namespace std;

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
        dijkstra(roads, numberOfTowns, 1);
        for (int i = 0; i < numberOfTowns; i++)
        {
            delete[] roads[i];
        }
        delete[] roads;
    }
}

