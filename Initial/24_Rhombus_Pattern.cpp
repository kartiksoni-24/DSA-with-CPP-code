#include <iostream>
using namespace std;

int main()
{
    // 2nd
    int n = 7;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            cout << ' ';
        }
        for (int j = 0; j < n; j++)
        {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}
