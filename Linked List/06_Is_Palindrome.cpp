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

    int size()
    {
        Node *h = head;
        int sz = 0;

        while (h != NULL)
        {
            sz += 1;
            h = h->next;
        }

        return sz;
    }

    Node *reverse(Node *m)
    {
        Node *prev = NULL;
        Node *curr = m;
        Node *next;

        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }
        return prev;
    }

    void helper(Node *m, Node *h)
    {
        Node *second = reverse(m);
        while (second != NULL)
        {
            if (second->data != h->data)
            {
                cout << "Not a palindrome\n";
                
                return;
            }
            h = h->next;
            second = second->next;
        }
        cout << "It is a Palindrome\n";
  
        return;
    }

    void isPalindrome()
    {
        int sz = size();
        Node *h = head;
        Node *m = head;
        int i = 1;
        if (sz % 2 == 0)
        {
            int mid = (sz / 2) + 1;
            while (i < mid)
            {
                m = m->next;
                i++;
            }
            helper(m, h);
        }
        else
        {
            int mid = (sz / 2) + 2;

            while (i < mid)
            {
                m = m->next;
                i++;
            }
            helper(m, h);
        }
    }
};

int main()
{
    List ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(6);
    ll.push_back(1);

    ll.isPalindrome();
}