// Problem:
// Print every subarray sum and find the largest one.
//
// Approach:
// Generate every start and end index, then sum the chosen subarray from scratch.
//
// Complexity:
// Time: O(n^3)
// Space: O(1)
#include <iostream>
using namespace std;

void subArrSum(int arr[], int n)
{
    int maxSum = INT16_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int currSum = 0;
            for (int k = i; k <= j; k++)
            {
                currSum += arr[k];
            }
            cout << currSum << ",";
            maxSum = max(maxSum, currSum);
        }
        cout << endl;
    }
    cout << "Max sum is : " << maxSum;
}

int main()
{
    int arr[] = {2, -3, 6, -5, 4, 2};
    int n = sizeof(arr) / sizeof(int);

    subArrSum(arr, n);

    return 0;
}
