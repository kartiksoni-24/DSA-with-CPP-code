#include <iostream>
using namespace std;

void printArr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {3,6,1,8,5};
    int n = sizeof(arr) / sizeof(int);

    int i = 0, j = n-1;

    while(i < j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;

        i++;
        j--;
    }

    printArr(arr, n);
}
