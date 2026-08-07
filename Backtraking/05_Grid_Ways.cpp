#include<iostream>
using namespace std;

int findWays(int r, int c, int n ,int m, string ans){
    if(r == n-1 && c == m-1){
        cout << ans << endl; // print path
        return 1;
    }

    if(r >= n || c >= m){
        return 0;
    }

    int val1 = findWays(r, c+1, n, m, ans+"R");
    int val2 = findWays(r+1, c, n, m, ans+"D");

    return val1+val2;
}

int main(){
    cout << findWays(0, 0, 4, 4 , "");
    return 0;
}