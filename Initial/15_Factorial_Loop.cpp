#include <iostream>
using namespace std;

int main()
{
    // --------------------------------Factorial--------------------------------------------
    int num = 5, fact = 1;

    for (int i = 1; i <= num; i++)
    {
        fact *= i;
    }

    cout << "Factorial is :" << fact;
    return 0;
}
