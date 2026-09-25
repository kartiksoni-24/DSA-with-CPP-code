// Problem:
// Print Floyd's triangle with consecutive numbers.
//
// Approach:
// Increase a counter after every printed value while growing each row by one number.
//
// Complexity:
// Time: O(n^2)
// Space: O(1)
#include <iostream>
using namespace std;

int main()
{
    // ----------------------------------floyd's triangle-------------------------------------
    int n = 5, num = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << num++ << " ";
        }
        cout << endl;
    }

    return 0;
}
