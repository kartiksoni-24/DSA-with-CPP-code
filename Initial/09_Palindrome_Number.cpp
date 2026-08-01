#include <iostream>
#include <cmath>
using namespace std;

void isPalindrom(int n)
{
    int reverse = 0, OG = n;
    while (n > 0)
    {
        int lastDigit = n % 10;
        n /= 10;
        reverse = reverse * 10 + lastDigit;
    }

    if (OG == reverse)
    {
        cout << OG << " is a palindrom";
    }
    else
    {
        cout << OG << " is not a palindrom";
    }
}

int main()
{
    isPalindrom(121);
    return 0;
}
