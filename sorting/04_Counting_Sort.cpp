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

void countingSort(int arr[], int n)
{
    int minVal = INT_MAX, maxVAl = INT_MIN;
    int freq[10000] = {0};

    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
        minVal = min(minVal, arr[i]);
        maxVAl = max(maxVAl, arr[i]);
    }

    for (int i = minVal, j = 0; i <= maxVAl; i++)
    {
        while (freq[i] > 0)
        {
            arr[j++] = i;
            freq[i]--;
        }
    }
    printArr(arr, n);
}

int main()
{
    int arr[] = {1, 3, 2, 1, 4, 5, 6, 5};
    int n = sizeof(arr) / sizeof(int);

    countingSort(arr, n);
    return 0;
}
