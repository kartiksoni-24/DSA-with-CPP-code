#include <iostream>
#include<vector>
using namespace std;

// --------------------------------------------last occurance------------------------------------
int lastOcc(vector<int> vec, int i, int target){
    if(i == vec.size()){
        return -1;
    }

    int idx = lastOcc(vec, i+1, target);

    if(idx == -1){
        if(vec[i] == target){
            return i;
        }
    }

    return idx;
}

int main()
{
    vector<int> vec = {1,2,3,4,5,4};
    cout << lastOcc(vec, 0, 41);
    return 0;
}
