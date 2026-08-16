#include<iostream>
#include<queue>
using namespace std;

void print(queue<int> q){
    cout << q.size()<<endl;
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << "\n";
}

void interleave2Queue(queue<int>& q){ // O(n)
    queue<int> firstQ;
    int n = q.size();
    for(int i = 0; i < n/2 ; i++){
        firstQ.push(q.front());
        q.pop();
    }

    while (!firstQ.empty())
    {
        q.push(firstQ.front());
        firstQ.pop();
        q.push(q.front());
        q.pop();
    }

    
}

int main(){
    queue<int> q;
    for (int i = 1; i <= 10; i++)
    {
        q.push(i);
    }
    print(q);
    interleave2Queue(q);
    print(q);
    return 0;
}