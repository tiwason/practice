#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Graph
{
    int v;
    vector<int>* adjList;
};

Graph* createGraph(int V)
{
    Graph* graph = new Graph();
    graph->v = V;
    graph->adjList = new vector<int>[V];
    return graph;
}

void addEdge(Graph* graph, int u, int v) //edge u to v
{
    if(graph == NULL)
        return;
    
    graph->adjList[u].push_back(v);
}

void printGraph(Graph* graph)
{
    if(graph == NULL)
        return;
    
    for (int i=0; i<graph->v; i++)
    {
        cout << "Adjacency list of vertex "<<i << " : ";
        for (auto e: graph->adjList[i])
            cout << e <<" ,";
        cout <<endl;
    }

}

//checks if there is an edge between u and v
bool searchEdge(Graph* graph , int u, int v)
{
    if (graph)
    {
        vector<int>::iterator it = find(graph->adjList[u].begin()
                                    , graph->adjList[u].end(), v);
        return (it != graph->adjList[u].end());
    }    

    return false;
}

int main()
{
    Graph* graph = createGraph(5);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 0);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 1);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 1);
    addEdge(graph, 3, 4);
    addEdge(graph, 3, 2);
    addEdge(graph, 4, 0);
    addEdge(graph, 4, 1);
    addEdge(graph, 4, 3);

    printGraph(graph);
    cout <<endl;
    cout << searchEdge(graph, 3, 0) << endl;
    cout << searchEdge(graph, 0, 4) << endl;
    return 0;
}
