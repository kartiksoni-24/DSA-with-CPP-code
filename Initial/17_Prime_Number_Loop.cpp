// Problem:
// Check whether a number is prime.
//
// Approach:
// Try every possible divisor below the number and stop when one divides it.
//
// Complexity:
// Time: O(n)
// Space: O(1)
#include <iostream>
using namespace std;

int main()
{
    // -----------------------------------Prime number-----------------------------------------
    int n = 2;
    bool isPrime = true;

    if (n == 1 || n == 2)
    {
        cout << "Prime number";
        return 0;
    }

    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            isPrime = false;
            break;
        }
    }

    if (isPrime)
    {
        cout << "Prime number";
    }
    else
    {
        cout << "Not a primme number";
    }

    return 0;
}
