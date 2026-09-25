// Problem:
// Reverse the digits of a number.
//
// Approach:
// Move each last digit into a new number by multiplying the result by 10 first.
//
// Complexity:
// Time: O(d), where d is the number of digits
// Space: O(1)
#include <iostream>
using namespace std;

int main()
{
    int n = 10829, sum = 0;

    for (int i = 0; n > 0; i++)
    {
        int lD = n % 10;
        sum = sum * 10 + lD;
        n /= 10;
    }

    cout << sum;
    return 0;
}
