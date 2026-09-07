#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

void pairSum(vector<int>& vec, int target){ // O(n)
    unordered_map<int, int> m;

    for (int i = 0; i < vec.size(); i++)
    {
        int comp = target - vec[i];
        if(m.count(comp)){
            cout << "Pair [" << comp << " ," << vec[i] << "] = " << target << endl; // print values, we can also print the index.
            return;
        }

        m[vec[i]] = i;
    }
    cout << "No pair equal to " <<  target << " exist.";
}

int main(){
    vector<int> vec = {1,2,7,11,15,5,9};
    int target = 10;

    pairSum(vec,target);
    return 0;
}