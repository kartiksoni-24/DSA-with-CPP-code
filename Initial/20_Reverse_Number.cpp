#include <iostream>
using namespace std;

int main()
{
    int n = 10829, sum = 0;

    for (int i = 0; n > 0; i++)
    {
        int lD = n % 10;
        sum = sum * 10 + lD;
        n /= 10;
    }

    cout << sum;
    return 0;
}
