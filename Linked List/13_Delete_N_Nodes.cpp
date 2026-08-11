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

void delNNodeAfterM(Node *head, int m, int n)
{
    Node *h = head;

    while (h != NULL)
    {
        // Keep M nodes
        int i = 1;

        while (i < m && h != NULL)
        {
            h = h->next;
            i++;
        }

        // Fewer than M nodes remain
        if (h == NULL)
        {
            return;
        }

        // h is now at the M-th node
        Node *temp = h;

        // Delete next N nodes
        i = 1;

        while (i <= n && temp->next != NULL)
        {
            Node *toDelete = temp->next;

            temp->next = toDelete->next;

            delete toDelete;

            i++;
        }

        // Move to the next group
        h = temp->next;
    }
}

int main()
{
    List ll;

    for (int i = 1; i <= 10; i++)
    {
        ll.push_back(i);
    }

    print(ll.head);

    delNNodeAfterM(ll.head, 3, 2);

    print(ll.head);
}