// Problem:
// Find the sum of the second row of a matrix.
//
// Approach:
// Traverse the columns in row index 1 and add their values.
//
// Complexity:
// Time: O(m)
// Space: O(1)
#include <iostream>
using namespace std;

void findTotal(int mat[][3], int n, int m)
{
    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        sum += mat[1][i];
    }

    cout << "sum is: " << sum;
}

int main()
{
    int mat[3][3] = {{2, 4, 2},
                     {7, 5, 7},
                     {4, 5, 6}};
    int n = 3, m = 3;

    findTotal(mat, n, m);
    return 0;
}
