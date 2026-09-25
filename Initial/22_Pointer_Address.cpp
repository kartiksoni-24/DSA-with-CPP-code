// Problem:
// Print a variable's memory address using a pointer and the address-of operator.
//
// Approach:
// Store the variable's address in a pointer, then print both address expressions.
//
// Complexity:
// Time: O(1)
// Space: O(1)
#include <iostream>
using namespace std;

int main()
{
    int a;
    int *b;
    a =10;
    b = &a;

    cout << b << " " << &a << endl;

    return 0;
}
