#include <iostream>
#include<vector>
using namespace std;

// -------------------------------------------first occurance-------------------------------------
int firstOcc(vector<int> arr, int i, int target){
    if(arr[i] == target){
        return i;
    }
    if(arr.size() == i ){
        return -1;
    }

    return firstOcc(arr, i+1, target);
}

int main()
{
    vector<int> vec = {1,2,3,4,5,4};
    cout << firstOcc(vec, 0, 43);
    return 0;
}
