// Problem:
// Find the largest sum of any contiguous subarray.
//
// Approach:
// For each start index, extend the end index and keep a running subarray sum.
//
// Complexity:
// Time: O(n^2)
// Space: O(1)
#include <iostream>
using namespace std;

int maxSubArrSum2(int *arr, int n)
{
    int maxSum = INT32_MIN, sum = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            maxSum = max(sum, maxSum);
        }
        sum = 0;
    }
    cout << endl;
    return maxSum;
}

int main()
{
    int arr[] = {2, -3, 6, -5, 4, 2};
    int n = sizeof(arr) / sizeof(int);

    cout << maxSubArrSum2(arr, n);

    return 0;
}
