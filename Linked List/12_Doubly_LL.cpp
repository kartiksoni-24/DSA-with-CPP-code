#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* prev;

        Node(int val){
            data = val;
            next = prev = NULL;
        }
};

class Doubly_LL{
    public:
        Node* head;
        Node* tail;

    Doubly_LL(){
        head = tail = NULL;
    }

    void push_front(int val){
        Node* newNode = new Node(val);

        if(head == NULL){
            head = newNode;
        } else{
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void pop_front(){
        Node* temp = head;

        head = head->next;
        if(head!= NULL){
            head->prev = NULL;
        }

        temp->next = NULL;
        delete temp;
    }

    void print(){
        Node* h = head;

        while(h != NULL){
            cout << h->data << " <=> ";
            h = h->next;
        }
        cout << "NULL" << endl;
    }
};

int main(){
    Doubly_LL ll;

    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_front(4);

    ll.print();

    ll.pop_front();
    ll.pop_front();

    ll.print();
    return 0;
}