#include <iostream>
using namespace std;

int getBit(int n, int i)
{
    int mask = 1 << i;
    if (!(mask & n))
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int main()
{
    cout << getBit(7, 1);
    return 0;
}
