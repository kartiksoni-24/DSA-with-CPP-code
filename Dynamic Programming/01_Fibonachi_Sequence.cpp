#include<iostream>
#include<vector>
using namespace std;

int fib(int n, vector<int>& f){ // O(n)
    if(n == 0|| n == 1){
        return n;
    }

    if(f[n] != -1){
        return f[n];
    }

    f[n] = fib(n-1, f) + fib(n-2, f);
    return f[n];
}

int main(){
    int n = 5;
    vector<int> f(n+1, -1);

    cout << fib(n, f);
    return 0;
}