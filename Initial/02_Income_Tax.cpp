// Problem:
// Calculate tax from annual income using the given income slabs.
//
// Approach:
// Use conditional checks to select the matching tax rate.
//
// Complexity:
// Time: O(1)
// Space: O(1)
#include <iostream>
using namespace std;

int main()
{
    int inc;

    cout << "Enter your Annual income (in Lakhs) : ";
    cin >> inc;

    if (inc < 5)
    {
        cout << "Your total tax value is 0";
    }
    else if (inc < 10)
    {
        cout << "Your total tax value is 20% which is equal to : " << (0.2 * inc) << "Lakhs";
    }
    else
    {
        cout << "Your total tax value is 30% which is equal to : " << (0.3 * inc) << "Lakhs";
    }
}
