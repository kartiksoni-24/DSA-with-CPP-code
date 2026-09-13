#include<iostream>
#include<vector>
using namespace std;

int countWays(int n, vector<int>& dp){
    if(n == 1 || n == 0){
        return 1;
    }

    if(dp[n] != -1){
        return dp[n];
    }

    dp[n] = countWays(n-1, dp) + countWays(n-2, dp);
    return dp[n];
}

int main(){
    int n = 5;
    vector<int> dp(n+1, -1);
    cout << countWays(n, dp);
    return 0;
}