#include<iostream>
#include<stack>
using namespace std;

template <class T>
void print(stack<T> s){
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

template <class T>
void pushAtBottom(stack<T>&s, T val){ // O(n)
    if(s.empty()){
        s.push(val);
        return;
    }

    T temp = s.top();
    s.pop();
    pushAtBottom(s, val);
    s.push(temp);
}

int main(){
    stack<char> s;

    s.push('3');
    s.push('2');
    s.push('1');
    print(s);
    pushAtBottom(s, '4');
    print(s);
    
}