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
