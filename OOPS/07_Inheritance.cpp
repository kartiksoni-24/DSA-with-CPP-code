// Problem:
// Create a dog class that reuses properties and behavior from an animal class.
//
// Approach:
// Use public inheritance so Dog receives Animal's public members.
//
// Complexity:
// Time: O(1)
// Space: O(1)
#include <iostream>
using namespace std;

class Animal
{
public:
    int legs;

    void eat()
    {
        cout << "Eating";
    }

    void run()
    {
        cout << "running";
    }
};

class Dog : public Animal
{
    void bark()
    {
        cout << "wooa";
    }
};

int main()
{
    Dog d;
    d.legs = 4;
    cout << d.legs << endl;
    d.eat();
}
