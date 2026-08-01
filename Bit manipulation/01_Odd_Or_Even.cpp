#include <iostream>
using namespace std;

void oddOrEven(int n)
{
    if (n & 1 == 0)
    {
        cout << "it is even.";
    }
    else
    {
        cout << "it is odd";
    }
}

int main()
{
    oddOrEven(47);
    return 0;
}
