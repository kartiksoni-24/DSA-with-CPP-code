#include <iostream>
using namespace std;

int clearBit(int n, int i)
{
    int bitMask = ~(1 << i);
    return (n & bitMask);
}

int main()
{
    cout << clearBit(7, 2);
    return 0;
}
