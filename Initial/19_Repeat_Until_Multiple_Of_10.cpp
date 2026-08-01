#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter any number : ";
    cin >> n;

    for (int i = 0; true; i++)
    {
        if (n % 10 == 0)
        {
            break;
        }
        cout << "Enter any number : ";
        cin >> n;
    }

    cout << "Now you are out of loop";
    return 0;
}
