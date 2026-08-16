#include<iostream>
#include<stack>
#include<queue>
using namespace std;

void reverse(queue<int>& q){
    stack<int> s;
    while (!q.empty())
    {
        s.push(q.front());
        q.pop();
    }

    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
    
}

void reverseUsingRec(queue<int>& q){
    if(q.empty()){
        return;
    }
    
    int x = q.front();
    q.pop();

    reverseUsingRec(q);

    q.push(x);
}

int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    reverseUsingRec(q);
    while(!q.empty()){
        cout << q.front()<< " ";
        q.pop();
    }
}