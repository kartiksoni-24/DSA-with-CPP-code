#include<iostream>
using namespace std;

void printAllOcc(int arr[], int n, int key, int i){
    if(i == n){
        return;
    }

    if(arr[i] == key){
        cout << i << " ";
    } 
    printAllOcc(arr, n, key, i+1);

}

int main(){
    int arr[] = {3,2,5,1,7,6,4,0,9,10,7};
    int n = sizeof(arr)/sizeof(int);
    printAllOcc(arr, n, 7, 0);
}