#include <iostream>
#include<vector>
using namespace std;

// ------------------------------------array is sorted--------------------------------------------
bool isSorted(int arr[], int n, int i){
    if(arr[i] > arr[i+1]){
        return false;
    }
    if(i == n-1){
        return true;
    }

    return isSorted(arr, n, i+1);
}

int main()
{
    int arr[] = {1,2,3,4,2,5};
    int n = sizeof(arr)/sizeof(int);
    cout<<isSorted(arr,n, 0);
    return 0;
}
