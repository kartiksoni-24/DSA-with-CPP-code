#include <iostream>
using namespace std;

int main()
{
    int n = 10829;

    for (int i = 0; n != 0; i++)
    {
        int lastDigit = n % 10;
        // int check = lastDigit % 2;

        cout << lastDigit;

        n /= 10;
    }

    return 0;
}
