#include <iostream>
using namespace std;

void checkPow(int n)
{
    if (((n) & (n - 1)) == 0)
    {
        cout << "power of 2";
    }
    return;
}

int main()
{
    checkPow(5);
    return 0;
}
