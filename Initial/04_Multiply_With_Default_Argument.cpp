// Problem:
// Multiply two numbers when the second number can use a default value.
//
// Approach:
// Define the second function parameter with a default and return the product.
//
// Complexity:
// Time: O(1)
// Space: O(1)
#include <iostream>
#include <cmath>
using namespace std;

int mul(int a, int b = 9)
{
    return a * b;
}

int main()
{
    cout << mul(4);
    return 0;
}
