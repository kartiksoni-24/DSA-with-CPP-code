// Problem:
// Print the multiplication table for a number from 1 to 10.
//
// Approach:
// Loop through the multipliers and print the number times each one.
//
// Complexity:
// Time: O(1)
// Space: O(1)
#include <iostream>
using namespace std;

int main()
{
    // --------------------------------Table print-----------------------------------------
    int n = 2;
    for (int i = 1; i < 11; i++)
    {
        cout << n * i << endl;
    }

    return 0;
}
