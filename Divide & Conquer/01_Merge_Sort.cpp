#include<iostream>
#include<vector>
using namespace std;

void merge(int arr[], int si, int ei, int mid){ // O(n)
    vector<int> vec;
    int i = si, j = mid+1;

    while(i <= mid && j <= ei){
        if(arr[i] <= arr[j]){
            vec.push_back(arr[i]);
            i++;
        } else{
            vec.push_back(arr[j]);
            j++;
        }
    }

    while(i <= mid){
        vec.push_back(arr[i++]);
    }

    while(j <= ei){
        vec.push_back(arr[j++]);
    }

    for(int idx = si, x=0; idx <= ei; idx++){
        arr[idx] = vec[x++];
    }
}

void mergeSort(int arr[], int si, int ei){ //O(nlogn)
    if(si >= ei){
        return;
    }
    int mid = (si+ei)/2;

    mergeSort(arr, si, mid);
    mergeSort(arr, mid+1, ei);
    merge(arr, si,ei,mid);
}

void printArr(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        cout << arr[i]<< " ";
    }
    
}

int main(){
    int arr[] = {6,3,2,5,4,1};
    int n = sizeof(arr)/sizeof(int);
    mergeSort(arr, 0, n-1);
    printArr(arr, n);
    return 0;
}
