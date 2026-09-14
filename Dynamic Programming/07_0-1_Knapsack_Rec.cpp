#include<iostream>
#include<vector>
using namespace std;

int knapsack(vector<int>& val, vector<int>& wt, int W, int n){ // O(2^n)
    if(n == 0 || W == 0){
        return 0;
    }

    int itemVal = val[n-1];
    int itemWt = wt[n-1];

    if(itemWt <= W){
        int ans1 = knapsack(val, wt, W-itemWt, n-1) + itemVal; // include

        int ans2 = knapsack(val, wt, W, n-1); // exclude

        return max(ans1, ans2);
    } else{
        return knapsack(val, wt, W, n-1);
    }
}

int main(){
    vector<int> val = {15,14,10,45,30};
    vector<int> wt = {2,5,1,3,4};
    int W = 7, n = 5;
    
    cout << knapsack(val, wt, W, n);
    return 0;
}