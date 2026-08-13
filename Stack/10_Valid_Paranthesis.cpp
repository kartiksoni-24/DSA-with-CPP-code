#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool isValid(string str){
    stack<char> s;
    
    for (int i = 0; i < str.size(); i++) //O(n)
    {
        char ch = str[i];
        if (ch == '(' || ch == '{' || ch == '['){
            s.push(ch);
        } else{
            if(s.empty()){
                return false;
            }

            char top = s.top();
            if ((top == '(' && ch == ')') || (top == '{' && ch == '}') || (top == '[' && ch == ']')){
                s.pop();
            } else{
                return false;
            }
        }
    }

    return s.empty();
}

int main(){
    string str = "({[()]})";
    string str2 = "[(){]}]";

    cout << isValid(str) << endl;
    cout << isValid(str2) << endl;

    return 0;
}