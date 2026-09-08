#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int subarrCoutnWithK(vector<int>& vec, int k){ // O(n)
    unordered_map<int, int> m; // sum, count
    m[0] = 1;
    int sum = 0, count = 0;

    for (int j = 0; j < vec.size(); j++)
    {
        sum += vec[j];

        if(m.count(sum - k)){
            count += m[sum-k];
        }

        if(m.count(sum)){
            m[sum]++;
        } else{
            m[sum] = 1;
        }
    }
    return count;
}

int main(){
    vector<int> vec = {10,2,-2,-20, 10};
    int k = -10;

    cout << subarrCoutnWithK(vec, k);
    return 0;
}