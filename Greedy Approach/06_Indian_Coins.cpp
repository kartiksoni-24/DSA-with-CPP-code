#include<iostream>
#include<vector>
using namespace std;

int minCoins(vector<int> coins, int V){ // O(n)
    int count = 0;
    int i =coins.size() - 1;
    while(true)
    {
        if(V >=coins[i]){
            count += V/ coins[i];
            cout << "coin give : " << coins[i] << "x" << V / coins[i] << endl;
            V %= coins[i];
        }
        if(V == 0){
            return count;
        }
        i--;
    }
    
}

int main(){
    vector<int> coins = {1,2,5,10,20,50,100,500,2000};

    cout << "Max coins needed : " << minCoins(coins, 1099);
    return 0;
}