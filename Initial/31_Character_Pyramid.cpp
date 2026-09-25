// Problem:
// Print a triangle of consecutive uppercase characters.
//
// Approach:
// Print one more character per row and increment the character after every print.
//
// Complexity:
// Time: O(n^2)
// Space: O(1)
#include <iostream>
using namespace std;

int main()
{
    // -------------------------------character pyramid-------------------------------------
    int n = 4;
    char ch = 'A';
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << ch << " "; // ch++
            ch++;
        }
        cout << endl;
    }

    return 0;
}
