// Problem:
// Find the sum of all digits in a number.
//
// Approach:
// Repeatedly take the last digit and remove it from the number.
//
// Complexity:
// Time: O(d), where d is the number of digits
// Space: O(1)
#include <iostream>
#include <cmath>
using namespace std;

int digitSum(int n)
{
    int sum = 0;
    while (n > 0)
    {
        int lD = n % 10;
        sum += lD;
        n /= 10;
    }

    return sum;
}

int main()
{
    cout << digitSum(123);
    return 0;
}
