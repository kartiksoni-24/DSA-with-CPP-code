#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter any number : ";
    cin >> n;

    int one = 0, two = 1;
    cout << one << " " << two << " ";

    for (int i = 0; i <= n; i++)
    {
        int fib = one + two;
        cout << fib << " ";

        one = two;
        two = fib;
    }

    return 0;
}
