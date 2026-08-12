#include<iostream>
using namespace std;

template<class T>
class Node{
    public:
    T data;
    Node* next;

    Node(T val){
        data = val;
        next = NULL;
    }
};

template<class T>
class Stack{
    public:
    Node<T>* head;

    Stack(){
        head = NULL;
    }

    void push(T val){
        //push front
        Node<T>* newNode = new Node<T>(val);
        if(head == NULL){
            head = newNode;
        }else{
            newNode->next = head;
            head = newNode;
        }
    }

    void pop(){
        //pop front
        Node<T>* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    T top(){
        return head->data;
    }

    bool isEmpty(){
        return head == NULL;
    }
};

int main(){
    Stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.pop();

    while(!s.isEmpty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout <<endl;
    return 0;
}