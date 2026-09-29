// Problem:
// Call a child's implementation through a parent-class pointer.
//
// Approach:
// Mark the parent method virtual so the call is resolved to the child's overridden method at runtime.
//
// Complexity:
// Time: O(1)
// Space: O(1)
#include <iostream>
#include <string>
using namespace std;

// runtime poly
// function overriding / virtual function

class Parent
{
public:
    void show()
    {
        cout << "parent show";
    }

    virtual void hello()
    {
        cout << "parent hello";
    }
};

class Child : public Parent
{
public:
    void show()
    {
        cout << "child show";
    }

    void hello()
    {
        cout << "child hello";
    }
};

int main()
{
    Child c1;
    Parent *ptr;

    ptr = &c1;
    ptr->hello();
    return 0;
}
