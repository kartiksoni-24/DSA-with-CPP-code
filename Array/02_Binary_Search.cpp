#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int key)
{
    int start = 0, end = n - 1;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (arr[mid] == key)
        {
            return mid;
        }
        else if (key > arr[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int key = 30, arr[] = {5, 7, 8, 10, 15, 30, 45};
    int n = sizeof(arr) / sizeof(int);
    int res = binarySearch(arr, n, key);
    cout << "key found at index " << res;
}
