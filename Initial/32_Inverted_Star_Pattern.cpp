// Problem:
// Print an inverted half pyramid of stars.
//
// Approach:
// Reduce the number of printed stars by one on each new row.
//
// Complexity:
// Time: O(n^2)
// Space: O(1)
#include <iostream>
using namespace std;

int main()
{
    // ---------------------------------inverted 3rd----------------------------------------
    int n = 5;
    for (int i = 0; i < n; i++)
    {
    for (int j = n; j > i; j--) // another way ,for (int j = 0; j < n-i+1; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }

    return 0;
}
