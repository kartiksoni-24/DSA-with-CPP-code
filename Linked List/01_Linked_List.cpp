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

    ~Node(){
        if(next != NULL){
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

    ~List(){
        if(head != NULL){
            delete head;
            head = NULL;
        }
    }

    void push_front(int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
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

    void insert(int val, int pos)
    {
        Node *newNode = new Node(val);
        Node *temp = head;
        int i = 0;
        while (i < pos - 1)
        {

            temp = temp->next;
            i++;
            if (temp == NULL)
            {
                cout << "Invalid position\n";
                return;
            }
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void pop_front(){
        if(head == NULL){
            cout << "LL is invalid";
            return;
        }

        Node* temp = head;
        head = head->next;

        temp->next = NULL;
        delete temp;
    }

    void pop_back(){
        Node* temp = head;

        while(temp->next->next != NULL){
            temp = temp->next;
        }

        temp->next = NULL;
        delete tail;
        tail = temp;
    }
};

int main()
{
    List ll;

    ll.push_back(3);
    ll.push_back(2);
    ll.push_back(1);
    ll.push_back(4);
    ll.push_back(5);

    ll.insert(600, 3);
    ll.pop_front();
    ll.pop_back();
    ll.printList();
}