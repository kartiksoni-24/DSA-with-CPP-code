#include<iostream>
#include<vector>
using namespace std;

int knapsack(vector<int>& val, vector<int>& wt, int W, int n, vector<vector<int>>& dp){ // O(n * W)
    if(n == 0 || W == 0){
        return 0;
    }

    int itemWt = wt[n-1];
    int itemVal = val[n-1];

    if(dp[n][W] != -1){
        return dp[n][W];
    }

    if(itemWt <= W){
        int ans1 = knapsack(val, wt, W-itemWt, n-1, dp) + itemVal; // include

        int ans2 = knapsack(val, wt, W, n-1, dp); // exclude

        dp[n][W] = max(ans1, ans2);
    } else{
        dp[n][W] = knapsack(val, wt, W, n-1, dp);
    }

    return dp[n][W];
}

int main(){
    vector<int> val = {15, 14, 10, 45, 30};
    vector<int> wt = {2, 5, 1, 3, 4};
    int W = 7, n = 5;
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));

    cout << knapsack(val, wt, W, n, dp);
    return 0;
}