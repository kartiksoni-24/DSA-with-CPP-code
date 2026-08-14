#include <iostream>
#include <stack>
#include <string>
using namespace std;

string decodeStr(string &str)
{
    stack<int> numberStack;
    stack<string> stringStack;

    string currstr = "";
    int num = 0;

    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];

        if (isdigit(ch))
        {
            num = num * 10 + (ch - '0');
        }
        else if (ch == '[')
        {
            // Save the current state
            numberStack.push(num);
            stringStack.push(currstr);

            // Start building the string inside []
            num = 0;
            currstr = "";
        }
        else if (ch == ']')
        {
            int repeat = numberStack.top();
            numberStack.pop();

            string previousStr = stringStack.top();
            stringStack.pop();

            string temp = "";

            for (int j = 0; j < repeat; j++)
            {
                temp += currstr;
            }

            currstr = previousStr + temp;
        }
        else
        {
            // Normal character
            currstr += ch;
        }
    }

    return currstr;
}

int main()
{
    string str = "2[abc]3[cd]ef";

    string res = decodeStr(str);

    cout << res << endl;

    return 0;
}