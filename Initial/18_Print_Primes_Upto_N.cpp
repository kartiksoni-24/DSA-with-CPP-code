#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter number : ";
    cin >> n;
    bool isPrime = true;

    for (int i = 2; i <= n; i++)
    {
        for (int j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                isPrime = false;
                // break;
            }
            if (isPrime)
            {
                cout << i << " ";
            }
        }
    }

    return 0;
}
