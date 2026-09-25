// Problem:
// Print a right-aligned half pyramid of stars.
//
// Approach:
// Print decreasing spaces followed by increasing stars on each row.
//
// Complexity:
// Time: O(n^2)
// Space: O(1)
#include <iostream>
using namespace std;

int main()
{
    // ----------------------------------inverted & rotatedd-------------------------------
    int n = 4;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            cout << " ";
        }
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}
