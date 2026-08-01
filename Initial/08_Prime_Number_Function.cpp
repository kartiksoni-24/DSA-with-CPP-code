#include <iostream>
#include <cmath>
using namespace std;

void isPrime(int n)
{
    bool isPrime = true;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            isPrime = false;
        }
    }

    if (isPrime)
    {
        cout << "prime number";
    }
    else
    {
        cout << "not a prime number";
    }
}

int main()
{
    isPrime(6);
    return 0;
}
