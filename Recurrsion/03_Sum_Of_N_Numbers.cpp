#include <iostream>
#include<vector>
using namespace std;

// -----------------------------sum of N numbers------------------------------------
int findSum(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return n + findSum(n - 1);
}

int main()
{
    cout << findSum(100);
    return 0;
}
