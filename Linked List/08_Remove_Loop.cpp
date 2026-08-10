#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
   
};

class List
{
public:
    Node *head;
    Node *tail;

    List()
    {
        head = NULL;
        tail = NULL;
    }
    

    void push_back(int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_back()
    {
        Node *h = head;

        while (h->next->next != NULL)
        {
            h = h->next;
        }

        h->next = NULL;
        delete tail;
        tail = h;
    }
};

void print(Node *head)
{
    Node *h = head;

    while (h != NULL)
    {
        cout << h->data << "->";
        h = h->next;
    }

    cout << "NULL";
}

void removeLoop(Node* head){
    Node* slow = head;
    Node* fast = head;
    bool isCycle = false;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            cout << "cycle exist\n";
            isCycle = true;
            break;
        }
    }

    if(!isCycle){
        cout << "No cycle exist\n";
        return;
    }

    slow = head;
    if (slow == fast)
    {
        while (fast->next != slow)
        {
            fast = fast->next;
        }
        fast->next = NULL;
    }
    else
    {
        Node *prev = fast;
        while (slow != fast)
        {
            slow = slow->next;
            prev = fast;
            fast = fast->next;
        }
        prev->next = NULL;
    }
}

int main(){
    List ll;

    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);
    ll.tail->next = ll.head;

    removeLoop(ll.head);
    print(ll.head);

    return 0;
}