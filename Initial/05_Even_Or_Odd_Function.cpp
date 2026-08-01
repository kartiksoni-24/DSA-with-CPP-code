#include <iostream>
#include <cmath>
using namespace std;

void checkNum(int n);

int main()
{
    checkNum(89);
    return 0;
}

void checkNum(int n)
{
    if (n % 2 == 0)
    {
        cout << n << " is an even number";
    }
    else
    {
        cout << n << " is an odd number";
    }
}
