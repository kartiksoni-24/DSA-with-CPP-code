// Problem:
// Check whether a number reads the same forward and backward.
//
// Approach:
// Reverse the digits and compare the reversed number with the original.
//
// Complexity:
// Time: O(d), where d is the number of digits
// Space: O(1)
#include <iostream>
#include <cmath>
using namespace std;

void isPalindrom(int n)
{
    int reverse = 0, OG = n;
    while (n > 0)
    {
        int lastDigit = n % 10;
        n /= 10;
        reverse = reverse * 10 + lastDigit;
    }

    if (OG == reverse)
    {
        cout << OG << " is a palindrom";
    }
    else
    {
        cout << OG << " is not a palindrom";
    }
}

int main()
{
    isPalindrom(121);
    return 0;
}
