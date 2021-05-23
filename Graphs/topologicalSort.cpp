#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

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

void topologicalSortUtil(Graph* g, int src, vector<bool>& visited, stack<int>& ans)
{
    visited[src] = true;
    for(auto e: g->adjList[src])
    {
        if(visited[e] == false)
            topologicalSortUtil(g, e, visited, ans);
    }
    ans.push(src);
}

void topologicalSort(Graph* g)
{
    if(g == NULL)
        return;

    stack<int> ans;
    vector<bool> visited(g->v, false);

    for(int i=0; i<g->v; i++)
    {
        if(visited[i] == false)
            topologicalSortUtil(g, i, visited, ans);
    }

    cout << "Topological Sort : ";
    while(!ans.empty())
    {
        cout << ans.top() << " ";
        ans.pop();
    }
    cout << endl;
}

int main()
{
    Graph* graph = createGraph(6);
    addEdge(graph, 5, 0);
    addEdge(graph, 5, 2);
    addEdge(graph, 4, 0);
    addEdge(graph, 4, 1);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 1);
    
    topologicalSort(graph);
    return 0;
}
