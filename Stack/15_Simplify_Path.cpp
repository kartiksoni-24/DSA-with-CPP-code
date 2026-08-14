#include <iostream>
#include <string>
#include <stack>
using namespace std;

string simplifyPath(string &str)
{
    stack<string> s;
    string currStr = "";
    for (int i = 0; i < str.size(); i++)
    {

        char ch = str[i];
        if (ch != '/')
        {
            currStr = currStr + ch;
        }
        else
        {
            if (currStr == "..")
            {
                if (!s.empty())
                {
                    s.pop();
                }
            }
            else if (currStr == "." || currStr == "")
            {
                // continue;
            }
            else
            {
                s.push(currStr);
            }
            currStr = "";
        }
    }

    string res = "";
    while (!s.empty())
    {
        res = "/" + s.top() + res;
        s.pop();
    }

    if (currStr != "")
    {
        res = res + "/" + currStr;
    }

    return res;
}

int main()
{
    string str = "/.../a/../b/c/../d/./";
    cout << simplifyPath(str) << endl;
}