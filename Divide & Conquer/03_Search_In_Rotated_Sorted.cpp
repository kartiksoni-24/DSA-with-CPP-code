#include <iostream>
using namespace std;

int search(int arr[], int si, int ei, int key)
{ // O(log n)
    if (si > ei)
    {
        return -1;
    }

    int mid = si + (ei - si) / 2;

    if (arr[mid] == key)
    {
        return mid;
    }

    if (arr[si] < arr[mid])
    { // line L1
        // left side
        if (arr[si] <= key && key <= arr[mid])
        {
            return search(arr, si, mid - 1, key);
        }
        else
        { // right side
            return search(arr, mid + 1, ei, key);
        }
    }
    else
    { // line L2
        if (arr[mid] <= key && key <= arr[ei])
        { // right side
            return search(arr, mid + 1, ei, key);
        }
        else
        { // left side
            return search(arr, si, mid - 1, key);
        }
    }
}

int main()
{
    int arr[] = {4, 5, 6, 7, 0, 1, 2};
    int n = 7;
    cout << search(arr, 0, n - 1, 0);
}