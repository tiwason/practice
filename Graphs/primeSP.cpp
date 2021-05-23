#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <utility>

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

void sieveOfErasthanos(vector<int>& primes)
{
    int n=9999;
    vector<bool> p(n+1, true);

    for (int i = 2; i*i <= n; i++)
    {
        if(p[i] == true)
        {
            for(int j=i; j<=n ; j+=i)
                p[j] = false;
        }
    }

    for (int i=1000; i<=n; i++)
    {
        if(p[i])
            primes.push_back(i);
    }
}

int bfs(Graph* g, int src, int dest)
{
    queue<pair<int, int> > q; //store level as well
    set<int> visited;
   
    q.push({src, 0});
    while(!q.empty())
    {
        pair<int, int> f = q.front();
        q.pop();
        visited.insert(f.first);
        for (auto n : g->adjList[f.first])
        {
            
            if(visited.find(n) == visited.end())
            {
                if(n == dest)
                    return (f.second + 1);
                
                q.push({n, f.second+1});
            }
        }
    }
    return -1;
}

bool compare(int a, int b)
{
    int count = 0;
    string s1 = to_string(a);
    string s2 = to_string(b);

    for (int i=0; i< s1.size(); i++)
    {
        if (s1[i] != s2[i])
            count++;
    }

    return (count == 1);
}

void shortestPath(int a, int b)
{
    vector<int> primes;
    sieveOfErasthanos(primes);

    Graph* g = createGraph(primes.size());
    int saveA, saveB;

    for(int i=0; i<primes.size(); i++)
    {
        if (primes[i] == a)
            saveA = i;
        
        if (primes[i] == b)
            saveB = i;
        
        for(int j=i+1; j<primes.size(); j++)
        {
            if (compare(primes[i], primes[j]))
            {   if (primes[j] == b)
                    cout << "adding edge "<< endl;
                addEdge(g, i, j);
            }
        }
    }

    int count = bfs(g, saveA, saveB);
    if (count == -1)
        cout << "No path found"<< endl;
    else
        cout << " Shortest path from "<< a <<" to " << b << " is " << count << endl;
    
}

int main()
{
    int prime1 = 1033;
    int prime2 = 8179;

    shortestPath(prime1, prime2);
}