#include <iostream>
using namespace std;

// ---------------------------------------------Q 1--------------------------------------------------
void findCount(int mat[][3], int n, int m)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 7)
            {
                count++;
            }
        }
    }
    cout << "Total count is : " << count;
}

int main()
{
    int mat[3][3] = {{2, 4, 2},
                     {7, 5, 7},
                     {4, 5, 6}};
    int n = 3, m = 3;

    findCount(mat, n, m);
    return 0;
}
