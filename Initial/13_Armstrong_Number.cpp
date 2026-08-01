#include <iostream>
using namespace std;

int main()
{
    // --------------------------------Armstrong number----------------------------------
    int n = 371, sum = 0, newN;
    newN = n;
    for (int i = 0; newN > 0; i++)
    {
        int lastDig = newN % 10;
        sum += lastDig * lastDig * lastDig;
        // newN += sum;
        newN /= 10;
    }

    if (n == sum)
    {
        cout << "Number is an armstrong";
    }
    else
    {
        cout << "Number is not an armstrong";
    }

    return 0;
}
