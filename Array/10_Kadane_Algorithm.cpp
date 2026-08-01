#include <iostream>
using namespace std;

int maxSubArrSum3(int arr[], int n)
{
    int maxSum = INT32_MIN, sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        maxSum = max(sum, maxSum);

        if (sum < 0)
        {
            sum = 0;
        }
    }
    return maxSum;
}

int main()
{
    int arr[] = {2, -3, 6, -5, 4, 2};
    int n = sizeof(arr) / sizeof(int);

    cout << maxSubArrSum3(arr, n);

    return 0;
}
