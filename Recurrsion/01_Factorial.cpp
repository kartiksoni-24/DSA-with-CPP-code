#include <iostream>
#include<vector>
using namespace std;

// -------------------------------factorial using recursion------------------------------------
int fact(int n)
{
    if (n == 1)
    {
        return 1;
    }

    return n * fact(n - 1);
}

int main()
{
    cout << fact(8);
    return 0;
}
