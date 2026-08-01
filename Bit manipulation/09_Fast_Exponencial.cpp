#include <iostream>
using namespace std;

void fastExponencial(int x, int n)
{
    int ans = 1;
    while (n > 0)
    {
        int lastBit = n & 1;
        if (lastBit)
        {
            ans *= x;
        }

        x *= x;
        n = n >> 1;
    }

    cout << ans;
}

int main()
{
    fastExponencial(3, 5);
    return 0;
}
