// Problem:
// Find the largest sum of any contiguous subarray.
//
// Approach:
// For each start index, extend the subarray while maintaining its running sum.
//
// Complexity:
// Time: O(n^2)
// Space: O(1)
#include <iostream>
using namespace std;

void subArrSum2(int arr[], int n)
{
    int maxSum = INT16_MIN;
    for (int i = 0; i < n; i++)
    {
        int currSum = 0;
        for (int j = i; j < n; j++)
        {

            currSum += arr[j];
            maxSum = max(maxSum, currSum);
        }
        // cout << endl;
    }
    cout << "Max sum is : " << maxSum;
}

int main()
{
    int arr[] = {2, -3, 6, -5, 4, 2};
    int n = sizeof(arr) / sizeof(int);

    subArrSum2(arr, n);

    return 0;
}
