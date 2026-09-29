// Problem:
// Create a user class that keeps sensitive data private and exposes controlled access.
//
// Approach:
// Store the id and password as private members and use public methods to set or read them.
//
// Complexity:
// Time: O(1)
// Space: O(1)
#include <iostream>
using namespace std;

class User
{
    int id, password;

public:
    string username;

    User(int id)
    {
        this->id = id;
    }

    int getPassword()
    {
        return password;
    }

    void setPassword(int password)
    {
        this->password = password;
    }
};

int main()
{
    User s1(10);
}
