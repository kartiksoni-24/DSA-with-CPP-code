// Problem:
// Find the largest sum of any contiguous subarray.
//
// Approach:
// Keep a running sum, reset it after a negative total, and track the maximum sum.
//
// Complexity:
// Time: O(n)
// Space: O(1)
#include <iostream>
using namespace std;

void subArrSum3(int arr[], int n)
{
    int maxSum = INT8_MIN;
    int currSum = 0;

    for (int i = 0; i < n; i++)
    {
        currSum += arr[i];
        maxSum = max(maxSum, currSum);
        if (currSum < 0)
        {
            currSum = 0;
        }
    }
    cout << "Max sum is : " << maxSum;
}

int main()
{
    int arr[] = {2, -3, 6, -5, 4, 2};
    int n = sizeof(arr) / sizeof(int);

    subArrSum3(arr, n);

    return 0;
}
