#include<iostream>
#include<queue>
using namespace std;

int timeToBuyTicket(int arr[], int n,int k){
    int time = 0;
    int  i = 0;
    while(true)
    {
        if (arr[i] == 0)
        {
            i++;
            if (i == n)
                i = 0;

            continue;
        }
        arr[i] = arr[i] -1;
        time++;
        if(arr[k] == 0 && i == k){
            return time;
        }
        i++;
        if(i == n){
            i = 0;
        }
    }
}

int main(){
    int arr[] = {5,1,1,1};
    int n = sizeof(arr)/ sizeof(int);

    cout << timeToBuyTicket(arr, n, 0);
}