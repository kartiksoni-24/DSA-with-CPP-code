#include <iostream>
#include <vector>
#include <list>
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

    bool helper(int src, int dest, vector<bool>& vis){
        if(src == dest){
            return true;
        }

        vis[src] = true;
        list<int> neighbors = l[src];
        
        for(auto &v : neighbors){
            if(!vis[v]){
                if(helper(v, dest, vis)){
                    return true;
                }
            }
        }
        return false;
    }

    bool hasPath(int src, int dest){ //O(V+E)
        vector<bool> vis(V, false);
        return helper(src, dest, vis);
    }
};

int main()
{
    Graph g(7);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);
    g.addEdge(5, 6);

    cout << (g.hasPath(0, 7) ? "True" : "False");
    return 0;
}