/*
 *
 *Kruskal's algorithm
 *
 */

#include <iostream>

using namespace std;

struct Edge
{
    int firstNode;
    int secondNode;
    int edgeLength;
    Edge *next;
};

struct EdgeList
{
    Edge *first;
};

void addEdge(int edge, int firstNode, int secondNode, EdgeList &myList)
{
    Edge **tmp = &(myList.first);
    while (*tmp && (*tmp)->edgeLength < edge)
    {
        tmp = &((*tmp)->next);
    }
    Edge *newEdge = new Edge;
    newEdge->edgeLength = edge;
    newEdge->firstNode = firstNode;
    newEdge->secondNode = secondNode;
    newEdge->next = *tmp;
    *tmp = newEdge;
}

bool doesEdgeMakeCycle(Edge *current, bool **array)
{
    return (array[current->firstNode - 1][current->secondNode - 1]) ? true : false;
}

void deleteEdge(Edge **curr)
{
    Edge *tmp = *curr;
    *curr = (*curr)->next;
    delete tmp;
}

void connectNodes(Edge *current, bool **array, int size)
{
    array[current->firstNode - 1][current->secondNode - 1] = true;
    array[current->secondNode - 1][current->firstNode - 1] = true;
    for (int i = 0; i < size; i++)
    {
        if (array[current->firstNode - 1][i])
        {
            array[current->secondNode - 1][i] = true;
            array[i][current->secondNode - 1] = true;
            for (int j = 0; j < size; j++)
            {
                if (array[current->secondNode - 1][j])
                {
                    array[i][j] = true;
                    array[j][i] = true;
                }
            }
        }
        if (array[current->secondNode - 1][i])
        {
            array[current->firstNode - 1][i] = true;
            array[i][current->firstNode - 1] = true;
            for (int j = 0; j < size; j++)
            {
                if (array[current->firstNode - 1][j])
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
    cout << "Enter the number of nodes and the number of edges: ";
    int numberOfNodes = 0;
    int numberOfEdges = 0;
    cin >> numberOfNodes >> numberOfEdges;
    cout << "\nEnter the edges (two nodes and length for each edge):\n";
    int tempNode1 = 0;
    int tempNode2 = 0;
    int tempEdge = 0;
    bool **edgeArray = new bool*[numberOfNodes];
    for (int i = 0; i < numberOfNodes; i++)
    {
        edgeArray[i] = new bool [numberOfNodes];
        for (int j = 0; j < numberOfNodes; j++)
        {
            edgeArray[i][j] = false;
        }
    }
    EdgeList edges;
    edges.first = NULL;
    for (int i = 0; i < numberOfEdges; i++)
    {
        cin >> tempNode1 >> tempNode2 >> tempEdge;
        addEdge(tempEdge, tempNode1, tempNode2, edges);
    }
    Edge **curr = &(edges.first);
    Edge **tmp = NULL;
    while (*curr)
    {
        if (!doesEdgeMakeCycle(*curr, edgeArray))
        {
            connectNodes(*curr, edgeArray, numberOfNodes);
            curr = &((*curr)->next);
        }
        else
        {
            tmp = curr;
            deleteEdge(tmp);
        }
    }
    curr = &(edges.first);
    cout << "\nHere are the edges of minimum spanning tree:\n";
    Edge *tmp2 = edges.first;
    while (*curr)
    {
        cout << "From " << (*curr)->firstNode << " to " << (*curr)->secondNode << " (length = " << (*curr)->edgeLength << ")\n";
        tmp2 = *curr;
        curr = &((*curr)->next);
        delete tmp2;
    }
    for (int i = 0; i < numberOfNodes; i++)
    {
        delete[] edgeArray[i];
    }
    delete[] edgeArray;
}

