#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

class Graph{
    int V;
    list<int> * l;
public:
    Graph(int V){
        this->V = V;
        l = new list<int> [V];
    }

    void addEdge(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void print(){
        for(int u = 0; u<V; u++){
            cout << u << " : ";
            for(auto &v : l[u]){
                cout << v << " ";
            }
            cout << endl;
        }
    }

    bool hasPathBFS(int src, int dest){
        queue<int> q;
        vector<bool> vis(V, false);

        q.push(src);
        vis[src] = true;

        while (q.size() > 0)
        {
            int u = q.front();
            q.pop();

            if(u == dest){
                return true;
            }

            for(auto &v : l[u]){
                if(!vis[v]){
                    if(v == dest) return true;
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
        return false;
    }
};

int main(){
    Graph g(7);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);
    g.addEdge(5, 6);

    cout << (g.hasPathBFS(0, 4) ? "Has path" : "No path");
    return 0;
}