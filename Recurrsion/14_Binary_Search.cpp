#include<iostream>
using namespace std;

int binarySearch(int arr[], int key, int i, int j){
    if(i>j){
        return -1;
    }
   
    // int mid = i+(j-i) /2;
    int mid = (i+j)/2;

    if(arr[mid] == key){
        return mid;
    } else if(arr[mid] < key){
        return binarySearch(arr, key, mid+1 ,j);
    } else{
        return binarySearch(arr, key, i, j-1);
    }

}

int main(){
    int arr[] = {2,4,6,8,10};
    int n = sizeof(arr)/sizeof(int);
    cout << binarySearch(arr, 3, 0, n-1);
    return 0;
}