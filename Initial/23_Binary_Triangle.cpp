// Problem:
// Print a triangle of alternating 1s and 0s.
//
// Approach:
// Print one more value on each row and toggle a boolean after every value.
//
// Complexity:
// Time: O(n^2)
// Space: O(1)
#include <iostream>
using namespace std;

int main()
{
    // 1st
    int n = 5;
    bool k = true;
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j <= i; j++)
        {

            cout << k << " ";
            k = !k;
        }
        cout << endl;
    }

    return 0;
}
