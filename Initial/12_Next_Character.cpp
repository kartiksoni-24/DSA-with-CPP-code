#include <iostream>
#include <cmath>
using namespace std;

char assingQ5(char ch)
{
    if (ch == 'z')
    {
        return 'a';
    }
    return ++ch;
}

int main()
{
    cout << assingQ5('z');
    return 0;
}
