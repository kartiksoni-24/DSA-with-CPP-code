#include <iostream>
using namespace std;

int main()
{
    // -------------------------------hollow rectangle-------------------------------------
    int n = 7;
    for (int i = 1; i <= n; i++)
    {
        cout << "*";
        for (int j = 2; j <= n; j++)
        {
            if (i == 1 || i == n)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << "*";
        cout << endl;
    }

    return 0;
}
