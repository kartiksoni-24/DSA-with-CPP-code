#include <iostream>
#include <string>
using namespace std;

void findPermu(string str, string ans) // O(n!), S O(n)
{
    if (str.size() == 0)
    {
        cout << ans << endl;
        return;
    }

    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];
        string nextStr = str;
        nextStr.erase(i, 1);
        findPermu(nextStr, ans + ch);
    }
}

int main()
{
    string str = "abc";
    findPermu(str, "");
}