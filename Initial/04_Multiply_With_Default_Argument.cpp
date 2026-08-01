#include <iostream>
#include <cmath>
using namespace std;

int mul(int a, int b = 9)
{
    return a * b;
}

int main()
{
    cout << mul(4);
    return 0;
}
