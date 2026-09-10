#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

void twoSum(vector<int> vec, int target){
    unordered_map<int ,int> m; // value, index
    for (int i = 0; i < vec.size(); i++)
    {
        int needed = target - vec[i];
        if(m.count(needed)){
            cout << i << ", " << m[needed];
            return;
        }
        m[vec[i]] = i;
    }
}

int main(){
    vector<int> vec = {3,2,4};
    int target = 6;

    twoSum(vec, target);
    return 0;
}