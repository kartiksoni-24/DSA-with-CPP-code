#include<iostream>
using namespace std;

// brute force approach

int inversionCount(int arr[], int i, int j, int count, int n){
    if(i == n){
        return count;
    }
    if (j == n)
    {
        return inversionCount(arr, i + 1, j = i + 1, count, n);
    }
    if(arr[i] > arr[j]){
        count+=1;
    }
    return inversionCount(arr, i, j+1, count, n);

    
}

int main(){
    int arr[] = {5, 5, 5};
    int n = sizeof(arr)/ sizeof(int);

    cout << "Inversion count : "  << inversionCount(arr, 0, 1, 0, n);
}