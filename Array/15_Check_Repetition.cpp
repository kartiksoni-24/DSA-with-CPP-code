#include <iostream>
using namespace std;

// -----------------------------------------Assignment 1 ----------------------------------------
bool checkRepitation(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int arr[] = {2, -3, 6, -5, 4, 2};
    int n = sizeof(arr) / sizeof(int);

    cout << checkRepitation(arr, n);

    return 0;
}
