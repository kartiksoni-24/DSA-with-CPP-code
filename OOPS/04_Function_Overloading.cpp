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
