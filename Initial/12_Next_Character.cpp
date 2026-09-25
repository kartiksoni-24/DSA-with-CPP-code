// Problem:
// Find the next lowercase character, wrapping z back to a.
//
// Approach:
// Handle z separately; otherwise increment the character.
//
// Complexity:
// Time: O(1)
// Space: O(1)
#include <iostream>
#include <cmath>
using namespace std;

char assingQ5(char ch)
{
    if (ch == 'z')
    {
        return 'a';
    }
    return ++ch;
}

int main()
{
    cout << assingQ5('z');
    return 0;
}
