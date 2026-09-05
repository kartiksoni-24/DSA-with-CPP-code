#include <iostream>
#include <queue>
#include <string>
#include<vector>
using namespace std;

struct comparePair{
    bool operator () (pair<string, int> &p1, pair<string ,int> &p2){
        return p1.second < p2.second;
    } 
};

int main()
{
    priority_queue<pair<string, int>, vector<pair<string, int>>, comparePair> pq;

    pq.push({"kartik", 96});
    pq.push({"soni", 76});
    pq.push({"ji", 24});

    while (!pq.empty())
    {
        cout << pq.top().first << ", " << pq.top().second << endl;
        pq.pop();
    }

    return 0;
}