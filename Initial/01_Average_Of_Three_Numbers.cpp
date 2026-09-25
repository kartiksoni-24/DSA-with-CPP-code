// Problem:
// Find the integer average of three input numbers.
//
// Approach:
// Add all three numbers and divide their sum by 3.
//
// Complexity:
// Time: O(1)
// Space: O(1)
#include <iostream>
using namespace std;

int main()
{
    int a, b, c;

    cout << "Enter a :";
    cin >> a;
    cout << "Enter b :";
    cin >> b;
    cout << "Enter c :";
    cin >> c;

    cout << "Average is : " << (a + b + c) / 3;
}
