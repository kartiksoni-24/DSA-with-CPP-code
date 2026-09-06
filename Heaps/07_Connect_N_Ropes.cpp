#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int connectNRopes(vector<int> vec){ // O(n)
    priority_queue<int, vector<int>, greater<int>> pq(vec.begin(), vec.end());
    int ans = 0;

    while(pq.size() > 1){
        int min1 = pq.top();
        pq.pop();
        int min2 = pq.top();
        pq.pop();

        ans += min1 + min2;
        pq.push(min1+min2);
    }
    return ans;
}

int main(){
    vector<int> vec = {4,2,3,6};
    cout << "Min Cost : " << connectNRopes(vec);
    return 0;
}