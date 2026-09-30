// Problem:
// Find the index of a target value in an array.
//
// Approach:
// Check each element from left to right until the target is found.
//
// Complexity:
// Time: O(n)
// Space: O(1)
#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int key = 10, arr[] = {4, 2, 9, 5, 10};
    int n = sizeof(arr) / sizeof(int);
    int res = linearSearch(arr, n, key);
    cout << "key found at index " << res;
}
