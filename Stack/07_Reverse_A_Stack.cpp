#include<iostream>
#include<stack>
using namespace std;

template <class T>
void print(stack<T> s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

template <class T>
void pushAtBottom(stack<T>& s, T val){
    if(s.empty()){
        s.push(val);
        return;
    }

    T temp = s.top();
    s.pop();
    pushAtBottom(s, val);
    s.push(temp);
}

template <class T>
void reverseAStack(stack<T>& s){
    if(s.empty()){
        return;
    }

    T temp = s.top();
    s.pop();
    reverseAStack(s);
    pushAtBottom(s, temp);
}

int main(){
    stack<int> s;

    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);

    print(s);
    reverseAStack(s);
    print(s);
}