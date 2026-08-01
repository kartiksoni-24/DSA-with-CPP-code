#include <iostream>
using namespace std;

int main()
{
    // 1st
    int n = 5;
    bool k = true;
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j <= i; j++)
        {

            cout << k << " ";
            k = !k;
        }
        cout << endl;
    }

    return 0;
}
