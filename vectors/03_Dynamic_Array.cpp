// Problem:
// Create an array of the requested size at runtime and print its values.
//
// Approach:
// Allocate memory with new, fill the array with consecutive numbers, then free it with delete[].
//
// Complexity:
// Time: O(n)
// Space: O(n)
#include <iostream>
using namespace std;

int main()
{
    int size;
    cin >> size;

    int *ptr = new int[size];
    int x = 1;
    for (int i = 0; i < size; i++)
    {
        ptr[i] = x;
        x++;
        cout << ptr[i] << " ";
    }
    delete[] ptr;
    // cout << *ptr;
    return 0;
}
