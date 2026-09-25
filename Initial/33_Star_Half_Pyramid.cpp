// Problem:
// Print a half pyramid of stars.
//
// Approach:
// Print one more star on each successive row.
//
// Complexity:
// Time: O(n^2)
// Space: O(1)
#include <iostream>
using namespace std;

int main()
{
    // ------------------------------------2nd video star-------------------------------------
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << '*';
        }
        cout << endl;
    }

    return 0;
}
