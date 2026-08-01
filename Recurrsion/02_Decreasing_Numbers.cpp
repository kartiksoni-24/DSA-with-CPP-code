#include <iostream>
#include<vector>
using namespace std;

// -----------------------------decreasing numbers-------------------------------
void printDecNo(int n)
{
    cout << n << " ";

    if (n <= 1)
    {
        return;
    }

    printDecNo(n - 1);
}

int main()
{
    printDecNo(24);
    return 0;
}
