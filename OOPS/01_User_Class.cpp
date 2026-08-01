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
