// Problem:
// Find the largest value in an array.
//
// Approach:
// Scan the array and keep the largest value seen so far.
//
// Complexity:
// Time: O(n)
// Space: O(1)
#include <iostream>
using namespace std;

int main()
{
    int arr[] = {3, 2, 7, 54, 0};
    int n = sizeof(arr) / sizeof(int), largest = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
        }
    }

    cout << "Largest is : " << largest;
}
