#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int countDistinct(vector<int> &vec){
    unordered_set<int> s;

    for (int i = 0; i < vec.size(); i++)
    {
        s.insert(vec[i]);
    }
    return s.size();
}

int main(){
    vector<int> vec = {1,2,3,4,2,1,5,3,1,2,6,7,8,9,6,7,8,5,6,0,9,3};
    cout << "Distinct values : " << countDistinct(vec);

    return 0;
}