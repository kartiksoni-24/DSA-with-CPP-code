// Problem:
// Print the digits of a number from right to left.
//
// Approach:
// Repeatedly print the last digit and remove it from the number.
//
// Complexity:
// Time: O(d), where d is the number of digits
// Space: O(1)
#include <iostream>
using namespace std;

int main()
{
    int n = 10829;

    for (int i = 0; n != 0; i++)
    {
        int lastDigit = n % 10;
        // int check = lastDigit % 2;

        cout << lastDigit;

        n /= 10;
    }

    return 0;
}
