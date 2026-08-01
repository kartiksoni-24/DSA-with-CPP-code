#include <iostream>
#include <cmath>
using namespace std;

int digitSum(int n)
{
    int sum = 0;
    while (n > 0)
    {
        int lD = n % 10;
        sum += lD;
        n /= 10;
    }

    return sum;
}

int main()
{
    cout << digitSum(123);
    return 0;
}
