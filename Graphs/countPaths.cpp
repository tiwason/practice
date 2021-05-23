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

void printPath(vector<int> path)
{
    for(auto v: path)
        cout << v << " -> ";
}

void dfs(Graph *g, int src, int dest, vector<int> path)
{
    if(g == NULL)
        return;
    
    path.push_back(src);
    for(auto e: g->adjList[src])
    {
        if (e == dest)
        {
            printPath(path); cout << e;
            cout << endl;
        }
        else
            dfs(g, e, dest, path);        
    }

}


void countPaths(Graph* g, int src, int dest)
{
    dfs(g, src, dest, {});
}

int main()
{
    Graph* graph = createGraph(5);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 2);
    

    countPaths(graph, 0, 4);
    
    return 0;
}
