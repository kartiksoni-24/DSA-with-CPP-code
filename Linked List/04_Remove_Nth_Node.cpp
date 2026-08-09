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
    ~Node()
    {
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
    }
};

class List
{
    Node *head;
    Node *tail;

public:
    List()
    {
        head = NULL;
        tail = NULL;
    }
    ~List()
    {
        if (head != NULL)
        {
            delete head;
            head = NULL;
        }
    }
    void printList()
    {
        Node *temp = head;

        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL";
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
        Node *temp = head;

        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = NULL;
        delete tail;
        tail = temp;
    }

    int llSize()
    {
        int sz = 0;
        Node *temp = head;

        while (temp != NULL)
        {
            sz += 1;
            temp = temp->next;
        }

        return sz;
    }

    void removeNth(int n)
    {
        int sz = llSize();
        Node *prev = head;

        for (int i = 1; i < (sz - n); i++)
        {
            prev = prev->next;
        }
        Node *toDel = prev->next;
        cout << toDel->data << " is going to dalete\n";
        prev->next = prev->next->next;
    }
};

int main()
{
    List ll;
    ll.push_back(3);
    ll.push_back(1);
    ll.push_back(4);
    ll.push_back(2);

    ll.removeNth(2);
    ll.printList();
}