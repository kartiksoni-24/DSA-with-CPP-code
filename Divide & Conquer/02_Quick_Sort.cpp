#include <iostream>
using namespace std;

int partition(int arr[], int si, int ei)
{
    int pivot = ei, i = si - 1;

    for (int j = si; j < pivot; j++)
    {
        if (arr[j] < arr[pivot])
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    i++;
    swap(arr[i], arr[pivot]);

    return i;
}

void quickSort(int arr[], int si, int ei)//O(nlogn) for average cases
{
    if (si >= ei)
    {
        return;
    }

    int pivot = partition(arr, si, ei);

    quickSort(arr, si, pivot - 1);
    quickSort(arr, pivot + 1, ei);
}

void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {6, 3, 2, 5, 7, 4};
    int n = 6;
    quickSort(arr, 0, n - 1);
    printArr(arr, n);
}