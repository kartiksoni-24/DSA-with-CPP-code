#include <iostream>
using namespace std;

void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

void bubbleSort(int arr[], int n)
{

    for (int i = 0; i < n - 1; i++)
    {
        bool isSwap = false; // for optimization
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                isSwap = true;
            }
        }

        if (isSwap == false)
        {
            printArr(arr, n);
            return;
        }
    }
    printArr(arr, n);
}

int main()
{
    int arr[] = {6, 1, 4, 9, 3};
    int n = sizeof(arr) / sizeof(int);

    bubbleSort(arr, n);
}
