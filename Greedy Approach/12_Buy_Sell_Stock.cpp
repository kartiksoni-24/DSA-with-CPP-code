#include<iostream>
#include<vector>
using namespace std;

int buySellStock(vector<int> vec){
    int previousMin = INT16_MAX;
    int maxProfit = 0;

    for (int i = 0; i < vec.size(); i++)
    {
        int currProfit = vec[i] - previousMin;
        maxProfit = max(maxProfit, currProfit);
        previousMin = min(previousMin, vec[i]); 
    }
    return maxProfit;
}

int main(){
    vector<int> vec = {7, 1, 5, 3, 6, 4};
    cout << buySellStock(vec);
    return 0 ;
}