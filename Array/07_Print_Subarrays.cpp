#include <iostream>
using namespace std;

void printSubArr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            for (int k = i; k <= j; k++)
            {
                cout << arr[k] << " ";
            }
            cout << "   ";
        }
        cout << endl;
    }
}

int main()
{
    int arr[] = {2, -3, 6, -5, 4, 2};
    int n = sizeof(arr) / sizeof(int);

    printSubArr(arr, n);

    return 0;
}
