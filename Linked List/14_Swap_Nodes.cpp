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

void swapNodes(Node*& head, int x, int y){
    Node* xHead = head;
    Node* yHead = head;
    Node* prevX = NULL;
    Node* prevY = NULL;

    while (xHead != NULL && xHead->data != x)
    {
        prevX = xHead;
        xHead = xHead->next;
    }
    while (yHead != NULL && yHead->data != y)
    {
        prevY = yHead;
        yHead = yHead->next;
    }

    if (xHead == NULL || yHead == NULL)
        return;
    
    Node* xNext = xHead->next;
    Node* yNext = yHead->next;

    // check for adjacent
    if (xNext == yHead)
    {
        if (prevX == NULL)
            head = yHead;
        else
            prevX->next = yHead;

        xHead->next = yNext;
        yHead->next = xHead;
        return;
    }
    if (yNext == xHead)
    {
        if (prevY == NULL)
            head = xHead;
        else
            prevY->next = xHead;

        yHead->next = xNext;
        xHead->next = yHead;
        return;
    }

    //check for head
    if(prevX == NULL){
        head = yHead;
        yHead->next = xNext;
        prevY->next = xHead;
        xHead-> next = yNext;
        return;
    }
    if (prevY == NULL)
    {
        head = xHead;
        xHead->next = yNext;
        prevX->next = yHead;
        yHead->next = xNext;
        return;
    }

    prevX->next = yHead;
    yHead->next = xNext;
    prevY->next = xHead;
    xHead->next = yNext;
}

int main(){
    List ll;

    ll.push_back(10);
    ll.push_back(20);
    ll.push_back(30);
    ll.push_back(40);
    // ll.push_back(5);

    print(ll.head);
    swapNodes(ll.head, 40, 10);
    print(ll.head);

    return 0;
}