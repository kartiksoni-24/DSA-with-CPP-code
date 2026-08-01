#include <iostream>
using namespace std;

void clearIBits(int num, int i)
{
    num = num & ((~0) << i);
    cout << num;
}

int main()
{
    clearIBits(15, 2);
    return 0;
}
