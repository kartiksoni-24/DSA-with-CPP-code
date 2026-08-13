#include<iostream>
#include<string>
#include<stack>
using namespace std;

template <class T>
void print(stack<T> s)
{
    while (!s.empty())
    {
        cout << s.top() << "";
        s.pop();
    }
    cout << endl;
}

void reverseStr(stack<char> s, string str){
    for (int i = 0; i < str.size(); i++)
    {
        s.push(str[i]);
    }
    print(s);
}

int main(){
    stack<char> s;
    string str = "kartik";

    cout << "Original String : " << str << endl;
    cout << "Reversed String : ";
    reverseStr(s, str);
    return 0;
}