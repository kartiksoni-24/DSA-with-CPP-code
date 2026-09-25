// Problem:
// Calculate the value of (a + b) squared.
//
// Approach:
// Use the expansion a^2 + b^2 + 2ab.
//
// Complexity:
// Time: O(1)
// Space: O(1)
#include <iostream>
#include <cmath>
using namespace std;

int assignQ3(int a, int b)
{
    return ((a * a) + (b * b) + 2 * (a * b));
}

int main()
{
    cout << assignQ3(2, 2);
    return 0;
}
