// Problem:
// Print values of different types using functions with the same name.
//
// Approach:
// Define show functions with different parameter types so the compiler selects the matching one.
//
// Complexity:
// Time: O(1)
// Space: O(1)
#include <iostream>
#include <string>
using namespace std;

// compile time
// function overloading
class Print
{
public:
    void show(int x)
    {
        cout << "int :" << x << endl;
    }
    void show(string str)
    {
        cout << "string : " << str;
    }
};

int main()
{
    Print obj;
    obj.show(2);
    obj.show("kartik soni");

    return 0;
}
