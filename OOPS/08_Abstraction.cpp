// Problem:
// Define shapes that must provide their own drawing behavior.
//
// Approach:
// Use an abstract base class with a pure virtual draw method and implement it in each shape.
//
// Complexity:
// Time: O(1)
// Space: O(1)
#include <iostream>
using namespace std;

class Shape
{
public:
    virtual void draw() = 0;
};

class Circle : public Shape
{
public:
    void draw()
    {
        cout << "draw circle\n";
    }
};

class Square : public Shape
{
public:
    void draw()
    {
        cout << "draw square";
    }
};

int main()
{
    Circle c1;
    c1.draw();

    return 0;
}
