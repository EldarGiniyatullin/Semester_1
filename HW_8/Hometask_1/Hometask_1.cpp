#include <iostream>
#include <fstream>

using namespace std;

void printNumber(int town, int &count)
{
    cout << "\n" << town << " (";
    if (count < 26)
        cout << (char)((count % 26) + 'a');
    else
        cout << "z" << count - 26;
    cout << ")";
}

void walkingTheGraph(bool **roads, bool* &notAdded, int numberOfTowns, int town, int &count)
{
    printNumber(town, count);
    count++;
    notAdded[town - 1] = false;
    for (int i = 0; i < numberOfTowns; i++)
    {
        if (notAdded[i] && roads[town - 1][i])
            walkingTheGraph(roads, notAdded, numberOfTowns, i + 1, count);
    }
}

int main()
{
    char buffer[40];
    cout << "Enter the name of file: ";
    cin.getline(buffer, 40);
    fstream fin;
    fin.open(buffer);
    if (!fin.is_open())
    {
        cout << "Could not open file";
    }
    else
    {
        int numberOfTowns = 0;
        int numberOfRoads = 0;
        fin >> numberOfTowns >> numberOfRoads;
        bool **roads = new bool*[numberOfTowns];
        bool *notAdded = new bool[numberOfTowns];
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
            roads[town1 - 1][town2 - 1] = true;
            roads[town2 - 1][town1 - 1] = true;
        }
        int mainTown = 0;
        fin >> mainTown;
        int count = 0;
        cout << "Numerification:\n";
        walkingTheGraph(roads, notAdded, numberOfTowns, mainTown, count);
        for (int i = 0; i < numberOfTowns; i++)
        {
            delete[] roads[i];
        }
        delete[] roads;
        delete[] notAdded;
    }
}

