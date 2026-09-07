#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    map<string, int> mp;

    mp["kartik"] = 22;
    mp["soni"] = 18;
    mp["ji"] = 12;
    mp["ji"] = 14;
    mp["xyz"] = 124;
    mp["pyq"] = 114;
    mp["abc"] = 4;

    if (mp.count("ki"))
    {
        cout << "present\n";
    }
    else
    {
        cout << "not present\n";
    }

    mp.erase("abc");
    for (pair<string, int> m : mp)
    {
        cout << m.first << "'s age is " << m.second << endl;
    }

    return 0;
}