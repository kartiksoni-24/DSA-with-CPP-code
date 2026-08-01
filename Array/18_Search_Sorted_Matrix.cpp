#include <iostream>
using namespace std;

void search(int mat[][4], int n, int m, int key)
{
    int i = 0, j = m - 1;

    while (i < n && j >= 0)
    {
        if (mat[i][j] == key)
        {
            cout << "Key found at " << i << ',' << j;
            return;
        }
        else if (key < mat[i][j])
        {
            j--;
        }
        else
        {
            i++;
        }
    }

    cout << "Key not found!";
}

int main()
{
    int matrix[4][4] = {{1, 2, 3, 4},
                        {5, 6, 7, 8},
                        {9, 10, 11, 12},
                        {13, 14, 15, 16}};
    int n = 4, m = 4;

    search(matrix, n, m, 174);
    return 0;
}
