#include <iostream>
#include <fstream>

using namespace std;

void connectNodes(int town1, int town2, bool **array, int size)
{
    array[town1 - 1][town2 - 1] = true;
    array[town2 - 1][town1 - 1] = true;
    for (int i = 0; i < size; i++)
    {
        if (array[town1 - 1][i])
        {
            array[town2 - 1][i] = true;
            array[i][town2 - 1] = true;
            for (int j = 0; j < size; j++)
            {
                if (array[town2 - 1][j])
                {
                    array[i][j] = true;
                    array[j][i] = true;
                }
            }
        }
        if (array[town2 - 1][i])
        {
            array[town1 - 1][i] = true;
            array[i][town1 - 1] = true;
            for (int j = 0; j < size; j++)
            {
                if (array[town1 - 1][j])
                {
                    array[i][j] = true;
                    array[j][i] = true;
                }
            }
        }
    }
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
        bool **roads = new bool*[numberOfTowns];
        bool *notAdded = new bool [numberOfTowns];
        for (int i = 0; i < numberOfTowns; i++)
        {
            notAdded[i] = true;
            roads[i] = new bool[numberOfTowns];
            for (int j = 0; j < numberOfTowns; j++)
                roads[i][j] = false;
        }
        int town1 = 0;
        int town2 = 0;
        for (int i = 0; i < numberOfRoads; i++)
        {
            fin >> town1 >> town2;
            connectNodes(town1, town2, roads, numberOfTowns);
        }
        cout << "Connected components:";
        for (int i = 0; i < numberOfTowns; i++)
        {
            if (notAdded[i])
            {
                cout << "\n" << i + 1;
                for (int j = i + 1; j < numberOfTowns; j++)
                {
                    if (roads[i][j])
                    {
                        notAdded[j] = false;
                        cout << " - " << j + 1;
                    }
                }
            }
            delete[] roads[i];
        }
        delete[] roads;
        delete[] notAdded;
    }
}

