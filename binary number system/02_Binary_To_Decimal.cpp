// Problem:
// Convert a binary number to its decimal value.
//
// Approach:
// Read digits from right to left and add each digit times its power of 2.
//
// Complexity:
// Time: O (log n)
// Space: O(1)
#include <iostream>
using namespace std;

int binToDec(int n)
{
    int pow = 1;
    int decNum = 0;
    while (n > 0)
    {
        int rem = n % 10;
        n /= 10;
        decNum += (rem * pow);
        pow *= 2;
    }
    return decNum;
}

int main()
{
    cout << binToDec(110);
    return 0;
}
