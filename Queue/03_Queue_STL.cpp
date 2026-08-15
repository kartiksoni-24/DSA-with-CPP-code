#include<iostream>
#include<queue>
using namespace std;

int main(){
    queue<int> q;

    q.push(2);
    q.push(4);
    q.push(4);
    q.push(4);

    while(!q.empty()){
        cout << q.front() << endl;
        q.pop();
    }

    return 0;
}