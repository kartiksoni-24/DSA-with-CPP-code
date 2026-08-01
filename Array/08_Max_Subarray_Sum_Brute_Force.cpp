#include <iostream>
using namespace std;

int maxSubArrSum1(int arr[], int n)
{
    int sum = 0, maxSum = INT32_MIN;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            for (int k = i; k <= j; k++)
            {
                sum += arr[k];
            }
            maxSum = max(sum, maxSum);
            sum = 0;
        }
    }
    cout << endl;
    return maxSum;
}

int main()
{
    int arr[] = {2, -3, 6, -5, 4, 2};
    int n = sizeof(arr) / sizeof(int);

    cout << maxSubArrSum1(arr, n);

    return 0;
}
