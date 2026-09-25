// Problem:
// Find the factorial of a number.
//
// Approach:
// Use a loop to multiply all integers from 1 through the number.
//
// Complexity:
// Time: O(n)
// Space: O(1)
#include <iostream>
using namespace std;

int main()
{
    // --------------------------------Factorial--------------------------------------------
    int num = 5, fact = 1;

    for (int i = 1; i <= num; i++)
    {
        fact *= i;
    }

    cout << "Factorial is :" << fact;
    return 0;
}
