#include <iostream>
#include <climits>
using namespace std;

void printArr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int curr = arr[i];
        int prev = i - 1;
        for (prev; prev >= 0 && arr[prev] > curr; prev--)
        {
            swap(arr[prev], arr[prev + 1]);
        }
        // arr[prev + 1] = curr;
    }
    printArr(arr, n);
}

int main()
{
    int arr[] = {5, 4, 7, 1, 2};
    int n = sizeof(arr) / sizeof(int);

    insertionSort(arr, n);
    return 0;
}
