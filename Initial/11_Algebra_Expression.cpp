#include <iostream>
#include <cmath>
using namespace std;

int assignQ3(int a, int b)
{
    return ((a * a) + (b * b) + 2 * (a * b));
}

int main()
{
    cout << assignQ3(2, 2);
    return 0;
}
