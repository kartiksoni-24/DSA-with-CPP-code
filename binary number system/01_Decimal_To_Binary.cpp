#include <iostream>
using namespace std;

int decToBin(int n)
{
    int pow = 1;
    int binNum = 0;
    for (int i = 0; n > 0; i++)
    {
        int rem = n % 2;
        n /= 2;
        binNum += (rem * pow);
        pow *= 10;
    }
    return binNum;
}

int main()
{
    cout << decToBin(32)<< endl;
    return 0;
}
