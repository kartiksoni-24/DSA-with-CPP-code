// Problem:
// Find which of three input numbers is the largest.
//
// Approach:
// Compare each number with the other two using conditional checks.
//
// Complexity:
// Time: O(1)
// Space: O(1)
#include <iostream>
using namespace std;

int main()
{
    int a, b, c, largest;

    cout << "Enter num 1 :";
    cin >> a;
    cout << "Enter num 2 :";
    cin >> b;
    cout << "Enter num 3 :";
    cin >> c;

    if (a > b && a > c)
    {
        cout << "num 1 is largest";
    }
    else if (b > a && b > c)
    {
        cout << "num 2 is largest";
    }
    else
    {
        cout << "num 3 is largest";
    }
}
