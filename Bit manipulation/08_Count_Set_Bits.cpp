#include <iostream>
using namespace std;

void countSetBits(int num)
{
    int count = 0;
    while (num > 0)
    {
        int lastBit = num & 1;
        count += lastBit;
        num = num >> 1;
    }
    cout << count;
}

int main()
{
    countSetBits(10);
    return 0;
}
