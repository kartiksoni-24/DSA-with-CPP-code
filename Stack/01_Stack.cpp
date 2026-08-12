#include<iostream>
#include<vector>
using namespace std;

template <class T> // by using template class we can use variable data type not fixed
class Stack{
    vector<T> vec;
public:
    void push(T val){
        vec.push_back(val);
    }

    void pop(){
        if(isEmpty()){
            cout << "Stack is empty";
            return;
        }
        vec.pop_back();
    }

    T top(){
        // if (isEmpty())
        // {
        //     cout << "Stack is empty";
        //     return -1; // because T is not a fixed data type so we don't know what to return
        // }
        int lastIdx = vec.size()-1;
        return vec[lastIdx];
    }

    bool isEmpty(){
        return vec.size() == 0;
    }
};

int main(){
    Stack<char> s;

    s.push('3');
    s.push('2');
    s.push('1');
    s.push('4');
    s.pop();

    while (!s.isEmpty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    
    return 0;
}