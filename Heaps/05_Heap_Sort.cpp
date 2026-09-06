#include<iostream>
#include<vector>
using namespace std;

void heapify(int i, vector<int>& vec, int n){
    int l = 2*i+1;
    int r = 2*i+2;
    int maxI = i;

    if(l < n && vec[l] > vec[maxI]){
        maxI = l;
    }

    if(r < n && vec[r] > vec[maxI]){
        maxI = r;
    }

    if(maxI != i){
        swap(vec[i], vec[maxI]);
        heapify(maxI, vec, n);
    }
}

void heapSort(vector<int>& vec){
    int n = vec.size();

    // step 1 - build max heap
    for (int i = n/2-1; i >= 0; i--)
    {
        heapify(i, vec, n);
    }
    
    // step 2 - move element to the correct position
    for (int i = n - 1; i >= 0; i--)
    {
        swap(vec[0], vec[i]);
        heapify(0, vec, i);
    }
}

int main(){
    vector<int> vec = {3,4,1,5,2};
    heapSort(vec);

    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    return 0;
}