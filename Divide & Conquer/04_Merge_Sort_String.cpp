#include<iostream>
#include<vector>
using namespace std;

void printArr(string arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

void mergeStr(string arr[], int si, int ei, int mid){
    vector<string> vec;
    int i = si, j = mid+1;

    while(i <= mid && j <= ei){
        if(arr[i] < arr[j]){
            vec.push_back(arr[i++]);

        }else{
            vec.push_back(arr[j++]);
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

void mergeSortStr(string arr[], int si, int ei){
    if(si >= ei){
        return ;
    }
    int mid = si + (ei-si)/2;

    mergeSortStr(arr, si, mid);
    mergeSortStr(arr, mid+1, ei);

    mergeStr(arr, si, ei, mid);
}

int main(){
    string arr[] = {"sun", "earth", "mars", "mercury"};
    int n = sizeof(arr)/sizeof(string);

    mergeSortStr(arr, 0, n-1);
    printArr(arr, n);
}