#include<iostream>
#include<list>
#include<vector>
using namespace std;

class Graph{ // undirected, unweighted graph
    int V;
    list<int> * l;

    public:
    Graph(int V){
        this->V = V;
        l = new list<int> [V];
    }

    void addEdge(int u, int v){ // u-----v
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void print(){
        for (int u = 0; u < V; u++)
        {
            list<int> neighbors = l[u];
            cout << u << " : ";
            for(auto &v : neighbors){
                cout << v << " ";
            }
            cout << endl;
        }
        
    }
};

int main(){
    Graph g(5);

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,4);
    g.addEdge(2,3);

    g.print();
    return 0;
}