// Problem:
// Keep reading numbers until one is divisible by 10.
//
// Approach:
// Use an infinite loop and exit when the current number has remainder 0 on division by 10.
//
// Complexity:
// Time: O(k), where k is the number of inputs read
// Space: O(1)
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter any number : ";
    cin >> n;

    for (int i = 0; true; i++)
    {
        if (n % 10 == 0)
        {
            break;
        }
        cout << "Enter any number : ";
        cin >> n;
    }

    cout << "Now you are out of loop";
    return 0;
}
