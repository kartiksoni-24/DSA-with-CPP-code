#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int val){
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

class List{
    Node* head;
    Node* tail;

 public:
    List(){
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

    int search(int key){
        Node* temp = head;

        for(int i = 0; temp != NULL; i++){
           
            if(temp->data == key){
                return i;
            }
            temp = temp->next;
        }
        return -1;
    }

    int searchRec(Node *temp,int key, int i){
        if(temp == NULL){
            return -1;
        }
        if (temp->data == key)
        {
            return i;
        }

        return searchRec(temp->next, key, i+1);
    }

    int helper(int key){
        return searchRec(head, key, 0);
    }
};

int main(){
    List ll;
    ll.push_back(3);
    ll.push_back(1);
    ll.push_back(4);
    ll.push_back(2);

    cout << ll.helper(4);
}