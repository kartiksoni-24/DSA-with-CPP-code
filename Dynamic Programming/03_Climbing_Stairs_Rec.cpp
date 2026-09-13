#include<iostream>
using namespace std;

int countWays(int n){ // O(2^n)
    if(n == 1 || n == 0){
        return 1;
    }

    return countWays(n-1) + countWays(n-2);
}

int main(){
    int n = 5;
    cout << countWays(n);
    return 0;
}