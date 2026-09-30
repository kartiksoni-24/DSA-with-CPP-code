// Problem:
// Reverse a character array in place.
//
// Approach:
// Use two pointers at the ends and swap characters while they move toward the center.
//
// Complexity:
// Time: O(n)
// Space: O(1)
#include <iostream>
#include <string.h>
using namespace std;

void reverseArr(char arr[], int n)
{
    int st = 0, end = n - 1;

    while (st < end)
    {
        swap(arr[st], arr[end]);
        st++;
        end--;
    }
}

int main()
{
    char word[] = "racecar";

    reverseArr(word, strlen(word));
    cout << word;
}
