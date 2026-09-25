// Problem:
// Print a pyramid where every row forms a palindromic number pattern.
//
// Approach:
// Print spaces, descending numbers, then ascending numbers for each row.
//
// Complexity:
// Time: O(n^2)
// Space: O(1)
#include <iostream>
using namespace std;

int main()
{
    // 3rd
    int n = 5;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            cout << " ";
        }

        for (int j = i; j >= 1; j--)
        {
            cout << j;
        }

        for (int j = 2; j <= i; j++)
        {
            cout << j;
        }

        cout << endl;
    }

    return 0;
}
