#include<iostream>
#include<list>
using namespace std;

class Graph{ // undirected weighted graph
    int V;
    list<pair<int, int>> * l;

    public:
    Graph(int V){
        this->V = V;
        l = new list<pair<int, int>> [V];
    }

    void addEdge(int u, int v, int wt){
        l[u].push_back({v, wt});
        l[v].push_back({u, wt});
    }

    void print(){
        for (int u = 0; u < V; u++)
        {
            cout << u << " : ";
            list<pair<int, int>> neighbors = l[u];
            for(pair<int, int> p : neighbors){
                cout << "(" << p.first << ", " << p.second << ")";
            }
            cout << endl;
        }
        
    }
};

int main(){
    Graph g(5);

    g.addEdge(0, 1, 5);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 3);
    g.addEdge(2, 3, 1);
    g.addEdge(2, 4, 2);

    g.print();
    return 0;
}