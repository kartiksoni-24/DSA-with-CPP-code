#include <iostream>
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

    cout << "NULL" << endl;
}

Node* splitAtMid(Node* head){
    Node* slow = head;
    Node* fast = head;
    Node* prev = NULL;

    while(fast != NULL && fast->next != NULL){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if(prev != NULL){
        prev->next = NULL;
    }

    return slow;
}

Node* reverse(Node* head){
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }
    return prev;
}

Node* zigZagLL(Node* head){
    Node* rightHead = splitAtMid(head);
    Node* rightHeadRev = reverse(rightHead);

    // alternate merging
    Node* left = head;
    Node* right = rightHeadRev;
    Node* tail = right;

    while(left != NULL && right != NULL){
        Node* nextLeft = left->next;
        Node* nextRight = right->next;
        
        left->next = right;
        right->next = nextLeft;

        tail = right;

        left = nextLeft;
        right = nextRight;
    }

    if(right != NULL){
        tail->next = right;
    }

    return head;
}

int main(){
    List ll;

    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    // ll.push_back(5);

    print(ll.head);
    ll.head = zigZagLL(ll.head);
    print(ll.head);
}