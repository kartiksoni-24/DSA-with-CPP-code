#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Graph
{
    int V;
    list<int> *l;
    bool isUndir;

public:
    Graph(int V, bool isUndir = true)
    {
        this->V = V;
        this->isUndir = isUndir;
        l = new list<int>[V];
    }

    void addEdge(int u, int v)
    {
        l[u].push_back(v);
        if(isUndir)
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

    bool isCycleHelper(int src, vector<bool>& vis, vector<bool>& recPath){
        vis[src] = true;
        recPath[src] = true;

        list<int> neighbors = l[src];
        for(auto &v : neighbors){
            if(!vis[v]){
                if(isCycleHelper(v, vis, recPath)){
                    return true;
                }
            } else{
                if(recPath[v]){
                    return true;
                }
            }
        }
        recPath[src] = false;
        return false;
    }

    bool isCycle(){
        vector<bool> vis(V, false);
        vector<bool> recPath(V, false);

        for(int i =0; i < V; i++){
            if(!vis[i]){
                if(isCycleHelper(i, vis, recPath)){
                    return true;
                }
            }
        }

        return false;
    }
};

int main()
{
    Graph g(4, false);

    g.addEdge(1,0);
    g.addEdge(0,2);
    g.addEdge(2,3);
    // g.addEdge(3,0);

    cout << (g.isCycle() ? "Cycle present" : "No Cycle");
    return 0;
}