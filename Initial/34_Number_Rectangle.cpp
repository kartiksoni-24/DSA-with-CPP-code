// Problem:
// Print a rectangle where each row repeats its row number.
//
// Approach:
// Use nested loops: the outer loop selects the row number and the inner loop repeats it.
//
// Complexity:
// Time: O(n^2)
// Space: O(1)
#include <iostream>
using namespace std;

int main()
{
    // -------------------------------1st video-------------------------------------------
    for (int i = 1; i < 5; i++)
    {
        for (int j = 1; j < 5; j++)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}
