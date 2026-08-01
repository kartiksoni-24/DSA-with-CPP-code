#include <iostream>
using namespace std;

int main()
{
    int a;
    int *b;
    a =10;
    b = &a;

    cout << b << " " << &a << endl;

    return 0;
}
