// Problem:
// Find the factorial of a number.
//
// Approach:
// Multiply all integers from 1 through the given number.
//
// Complexity:
// Time: O(n)
// Space: O(1)
#include <iostream>
#include <cmath>
using namespace std;

int findFact(int num)
{
    int fact = 1;
    for (int i = 1; i <= num; i++)
    {
        fact *= i;
    }

    return fact;
}

int main()
{
    cout << findFact(10);
    return 0;
}
