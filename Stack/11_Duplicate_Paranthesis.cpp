#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isDuplicate(string str)
{
    stack<char> s;

    for (int i = 0; i < str.size(); i++) // O(n)
    {
        char ch = str[i];

        if(ch != ')'){
            s.push(ch);
        } else{
            if(s.top() == '('){
                return true;
            }

            while(s.top() != '('){
                s.pop();
            }
            s.pop();
        }
    }
    return false;
}

int main()
{
    string str = "((a+b) + (c-d))";
    string str2 = "((a+b) + ((c)))";

    cout << isDuplicate(str) << endl;
    cout << isDuplicate(str2) << endl;

    return 0;
}