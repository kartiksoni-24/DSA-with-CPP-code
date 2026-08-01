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
    int arr[] = {4, 2, 9, 5, 10};
    int n = sizeof(arr) / sizeof(int);
    int copyArr[n];

    for (int i = 0; i < n; i++)
    {
        int j = n - i - 1;
        copyArr[i] = arr[j];
        // arr[i] = copyArr[i];
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = copyArr[i];
    }

    printArr(arr, n);
}
