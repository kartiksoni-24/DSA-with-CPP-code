// Problem:
// Find the number of elements in a vector.
//
// Approach:
// Subtract the begin iterator from the end iterator to get the element count.
//
// Complexity:
// Time: O(1)
// Space: O(1)
#include <iostream>
#include <vector>

// #include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<char> v = {'a', 'c', 'f', 'd', 'z'};

    // Finding size
    cout << (v.end() - v.begin());

    return 0;
}
