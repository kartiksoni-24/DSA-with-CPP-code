// Problem:
// Reverse an array using a separate copy array.
//
// Approach:
// Copy elements from the original array in reverse order, then copy them back.
//
// Complexity:
// Time: O(n)
// Space: O(n)
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
