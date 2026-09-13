#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Graph
{
    int V;
    list<int> *l;

public:
    Graph(int V)
    {
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int u, int v)
    {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void print()
    {
        for (int u = 0; u < V; u++)
        {
            cout << u << " : ";
            list<int> neighbors = l[u];
            for (auto &v : neighbors)
            {
                cout << v << " ";
            }
            cout << endl;
        }
    }

    void dfsHelper(int u, vector<bool> &vis)
    {
        cout << u << " ";
        vis[u] = true;
    
        list<int> neighbors = l[u];
        for (auto &v : neighbors)
        {
            if (!vis[v])
            {
                dfsHelper(v, vis);
            }
        }
    }

    void DFS()
    {
        vector<bool> vis(V, false);

        for (int i = 0; i < V; i++)
        {
            if(!vis[i]){
                dfsHelper(i, vis);
                cout << endl;
            }
        }
    }
};

int main()
{
    Graph g(10);

    g.addEdge(0,2);
    g.addEdge(2,5);
    g.addEdge(1,6);
    g.addEdge(6,4);
    g.addEdge(4,3);
    g.addEdge(4,9);
    g.addEdge(3,8);
    g.addEdge(3,7);
    
    g.print();
    g.DFS();

    return 0 ;
}