#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

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
    graph->adjList[v].push_back(u);
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

bool dfs(Graph* g, int s, int visited[], int degree[], int k)
{
    visited[s] = true;
   
    for(auto e : g->adjList[s])
    {
        if(degree[s] < k)
            degree[e]--;
       
        if (!visited[e])
        {
            if (dfs(g, e, visited, degree, k))
                    degree[s]--;
        }
    }
  
    return (degree[s] < k);
}

void printKCores(Graph* graph, int k)
{
    int visited[graph->v];
    int degree[graph->v];

    for(int i=0; i<graph->v; i++)
    {
        visited[i] = 0;
        degree[i] = graph->adjList[i].size();
    }

    for(int i =0; i<graph->v; i++)
    {
        if(!visited[i])
            dfs(graph, i, visited, degree, k);
    }

    //print
    cout << "Printing k cores" << endl;
    for(int i =0; i<graph->v; i++)
    { 
        if(degree[i] >= k)
        {
            cout << i << " -> ";
            for(auto e: graph->adjList[i])
            {
                if(degree[e] >= k)
                    cout << e << " ";
            }
        }
        cout << endl;
    }
}

int main()
{
    Graph* graph = createGraph(9);
    addEdge(graph, 0, 1); 
    addEdge(graph, 0, 2); 
    addEdge(graph, 1, 2); 
    addEdge(graph, 1, 5); 
    addEdge(graph, 2, 3); 
    addEdge(graph, 2, 4); 
    addEdge(graph, 2, 5); 
    addEdge(graph, 2, 6); 
    addEdge(graph, 3, 4); 
    addEdge(graph, 3, 6); 
    addEdge(graph, 3, 7); 
    addEdge(graph, 4, 6); 
    addEdge(graph, 4, 7); 
    addEdge(graph, 5, 6); 
    addEdge(graph, 5, 8); 
    addEdge(graph, 6, 7); 
    addEdge(graph, 6, 8);

    int k=3;
    printKCores(graph, k);
   
    return 0;
}
