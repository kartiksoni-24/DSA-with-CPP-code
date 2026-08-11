#include <iostream>
#include <list>
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

void oddEvenLL(Node *head)
{
    Node *evenHead = NULL;
    Node *evenTail = NULL;
    Node *oddHead = NULL;
    Node *oddTail = NULL;

    Node *curr = head;
    while (curr != NULL)
    {
        if (curr->data % 2 == 0)
        {
            if (evenHead == NULL)
            {
                evenHead = curr;
                evenTail = curr;
            }
            else
            {
                evenTail->next = curr;
                evenTail = curr;
            }
        }
        else
        {
            if (oddHead == NULL)
            {
                oddHead = curr;
                oddTail = curr;
            }
            else
            {
                oddTail->next = curr;
                oddTail = curr;
            }
        }
        curr = curr->next;
    }
    evenTail->next = oddHead;
    if (oddHead != NULL)
    {
        oddTail->next = NULL;
    }
}

int main()
{
    List ll;

    ll.push_back(8);
    ll.push_back(12);
    ll.push_back(10);
    ll.push_back(5);
    ll.push_back(4);
    ll.push_back(1);
    ll.push_back(6);

    oddEvenLL(ll.head);
    print(ll.head);
}