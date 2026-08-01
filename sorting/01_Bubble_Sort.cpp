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

void bubbleSort(int *arr, int n)
{
    for (int j = 0; j < n - 1; j++)
    {
        for (int i = 0; i < n - j - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                // int temp = arr[i];
                // arr[i] = arr[i + 1];
                // arr[i + 1] = temp;
                swap(arr[i], arr[i + 1]);
            }
        }
    }

    printArr(arr, n);
}

int main()
{
    int arr[] = {5, 4, 7, 1, 2};
    int n = sizeof(arr) / sizeof(int);

    bubbleSort(arr, n);
    return 0;
}
