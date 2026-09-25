// Problem:
// Convert a decimal number to its binary representation.
//
// Approach:
// Repeatedly divide by 2 and place each remainder at the next binary digit position.
//
// Complexity:
// Time: O(log n)
// Space: O(1)
#include <iostream>
using namespace std;

int decToBin(int n)
{
    int pow = 1;
    int binNum = 0;
    for (int i = 0; n > 0; i++)
    {
        int rem = n % 2;
        n /= 2;
        binNum += (rem * pow);
        pow *= 10;
    }
    return binNum;
}

int main()
{
    cout << decToBin(32)<< endl;
    return 0;
}
