#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int largestSubarrWith0Sum(vector<int>& vec){ // O(n) almost
    unordered_map<int, int> m; // sum, index
    int sum = 0, ans = 0;

    for (int j = 0; j < vec.size(); j++)
    {
        sum += vec[j];

        if(m.count(sum)){
            int currLen = j - m[sum];
            ans = max(ans,currLen);
        } else{
            m[sum] = j;
        }
    }
    return ans;
}

int main(){
    vector<int> vec= {15, -2, 2, -8, 1, 7, 10};
    cout << "largest subarray with zero sum : " << largestSubarrWith0Sum(vec);

    return 0;
}