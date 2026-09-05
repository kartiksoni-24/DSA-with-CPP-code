#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    priority_queue<int> pq; // for max heap 
    priority_queue<int, vector<int>, greater<int>> pq1; // for min heap

    pq.push(32);
    pq.push(22);
    pq.push(42);
    pq.push(27);
    pq.push(16);
    pq.push(59);
    pq.push(66);

    pq1.push(32);
    pq1.push(22);
    pq1.push(42);
    pq1.push(27);
    pq1.push(16);
    pq1.push(59);
    pq1.push(66);

    // cout << pq.top();
    while (!pq.empty())
    {
        cout << pq.top() << endl; // decending order
        pq.pop();
    }
    cout << "------------------------------\n";
    while (!pq1.empty())
    {
        cout << pq1.top() << endl; // ascending order
        pq1.pop();
    }

    return 0;
}