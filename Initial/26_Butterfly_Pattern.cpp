// Problem:
// Print a butterfly pattern made of stars and spaces.
//
// Approach:
// Build the upper and lower halves with mirrored star groups around a shrinking gap.
//
// Complexity:
// Time: O(n^2)
// Space: O(1)
#include <iostream>
using namespace std;

int main()
{
    // ----------------------------------butterfly-----------------------------------------
    int n = 4;
    for (int i = n; i >= 1; i--)
    {
        for (int j = 0; j <= n - i; j++)
        {
            cout << "*";
        }

        for (int j = 1; j <= i * 2 - 2; j++)
        {
            cout << " ";
        }

        for (int j = 0; j <= n - i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= n - i; j++)
        {
            cout << "*";
        }

        for (int j = 1; j <= i * 2 - 2; j++)
        {
            cout << " ";
        }

        for (int j = 0; j <= n - i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}
