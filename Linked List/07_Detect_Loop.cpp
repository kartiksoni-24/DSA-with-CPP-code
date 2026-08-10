#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data= val;
        next = NULL;
    }
    ~Node(){
        if(next != NULL){
            delete next;
            next = NULL;
        }
    }
};

class List
{
public:
    Node* head;
    Node* tail;

   
    List(){
        head = NULL;
        tail =NULL;
    }
    ~List(){
        if(head != NULL){
            delete head;
            head = NULL; 
        }
    }

    void push_back(int val){
        Node* newNode = new Node(val);

        if(head == NULL){
            head= tail = newNode;
        } else{
            tail->next = newNode;
            tail = newNode;
        }

    }

    void pop_back(){
        Node* h = head;

        while(h->next->next != NULL){
            h = h->next;
        }

        h->next = NULL;
        delete tail;
        tail = h;
    }
};

void print(Node* head)
{
    Node *h = head;

    while (h != NULL)
    {
        cout << h->data << "->";
        h = h->next;
    }

    cout << "NULL";
}

bool detectLoop(Node* head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            cout << "loop detected";
            return true;
        }
    }

    cout << "No loop detected";
    return false;
}

int main(){
    List ll;

    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);
    ll.push_back(6);
    // ll.tail->next = ll.head; // creates loop
    detectLoop(ll.head);
        return 0;
}