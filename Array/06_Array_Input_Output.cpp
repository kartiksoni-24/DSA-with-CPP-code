// Problem:
// Read an array from input and print its elements.
//
// Approach:
// Use one loop to read all values and another loop to print them.
//
// Complexity:
// Time: O(n)
// Space: O(n)
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }
}
