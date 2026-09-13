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

    bool detectCycleHelper(int src, int par, vector<bool>& vis){
        vis[src] = true;
        list<int> neighbors = l[src];

        for(auto &v : neighbors){
            if(!vis[v]){
                if(detectCycleHelper(v, src, vis)){
                    return true;
                }
            } else{
                if(v != par){
                    return true;
                }
            }
        }
        return false;
    }

    bool detectCycle(){
        vector<bool> vis(V, false);
        return detectCycleHelper(0, -1, vis);
    }
};

int main()
{
    Graph g(5);

    g.addEdge(0,1);
    g.addEdge(1,2);
    // g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(0,4);

    cout << (g.detectCycle() ? "Cycle present" : "No cycle");
    return 0;
}