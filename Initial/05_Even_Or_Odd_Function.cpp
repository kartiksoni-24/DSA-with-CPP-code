// Problem:
// Check whether a number is even or odd.
//
// Approach:
// Test the remainder after dividing the number by 2.
//
// Complexity:
// Time: O(1)
// Space: O(1)
#include <iostream>
#include <cmath>
using namespace std;

void checkNum(int n);

int main()
{
    checkNum(89);
    return 0;
}

void checkNum(int n)
{
    if (n % 2 == 0)
    {
        cout << n << " is an even number";
    }
    else
    {
        cout << n << " is an odd number";
    }
}
