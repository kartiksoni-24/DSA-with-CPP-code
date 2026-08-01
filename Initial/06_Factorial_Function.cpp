#include <iostream>
#include <cmath>
using namespace std;

int findFact(int num)
{
    int fact = 1;
    for (int i = 1; i <= num; i++)
    {
        fact *= i;
    }

    return fact;
}

int main()
{
    cout << findFact(10);
    return 0;
}
