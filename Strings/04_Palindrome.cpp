// Problem:
// Check whether a character array reads the same forward and backward.
//
// Approach:
// Compare matching characters from both ends while moving toward the center.
//
// Complexity:
// Time: O(n)
// Space: O(1)
#include <iostream>
#include <string.h>
using namespace std;

void isPalindrome(char arr[], int n)
{
    int st = 0, end = n - 1;
    bool isPalindrome = false;
    while (st < end)
    {
        if (arr[st] == arr[end])
        {
            isPalindrome = true;
            st++;
            end--;
        }
        else
        {
            isPalindrome = false;
            break;
        }
    }

    cout << isPalindrome;
}

int main()
{
    char word[] = "racecar";

    isPalindrome(word, strlen(word));
}
