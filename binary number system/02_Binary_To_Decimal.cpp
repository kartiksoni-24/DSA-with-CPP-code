#include <iostream>
using namespace std;

int binToDec(int n)
{
    int pow = 1;
    int decNum = 0;
    while (n > 0)
    {
        int rem = n % 10;
        n /= 10;
        decNum += (rem * pow);
        pow *= 2;
    }
    return decNum;
}

int main()
{
    cout << binToDec(110);
    return 0;
}
