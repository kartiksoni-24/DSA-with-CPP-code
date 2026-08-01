#include <iostream>
using namespace std;

void transpose(int mat[][3], int n, int m)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mat[j][i];
        }
        cout << endl;
    }
}

int main()
{
    int mat[3][3] = {{2, 4, 2},
                     {7, 5, 7},
                     {4, 5, 6}};
    int n = 3, m = 3;

    transpose(mat, n, m);
    return 0;
}
