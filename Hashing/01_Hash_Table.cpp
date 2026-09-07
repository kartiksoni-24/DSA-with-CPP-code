#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Node
{ // for linked list
public:
    int val;
    string key;
    Node *next;

    Node(string key, int val)
    {
        this->key = key;
        this->val = val;
        next = NULL;
    }

    ~Node()
    {
        if (next != NULL)
        {
            delete next;
        }
    }
};

class HashTable
{
    int totalSize;
    int currSize;
    Node **table;

    int hashFunction(string key)
    {
        int idx = 0;

        for (int i = 0; i < key.size(); i++)
        {
            idx = idx + (key[i] * key[i]) % totalSize;
        }
        return idx % totalSize;
    }

    void rehash()
    {
        Node **preTable = table;
        int preSize = totalSize;

        totalSize = 2 * totalSize;
        currSize = 0;
        table = new Node *[totalSize];

        for (int i = 0; i < totalSize; i++)
        {
            table[i] = NULL;
        }

        // copy previous data
        for (int i = 0; i < preSize; i++)
        {
            Node *temp = preTable[i];
            while (temp != NULL)
            {
                insert(temp->key, temp->val);
                temp = temp->next;
            }

            if (preTable[i] != NULL)
            {
                delete preTable[i];
            }
        }

        delete[] preTable;
    }

public:
    HashTable(int size = 5)
    {
        totalSize = size;
        currSize = 0;
        table = new Node *[totalSize];

        for (int i = 0; i < totalSize; i++)
        {
            table[i] = NULL;
        }
    }

    void insert(string key, int val)
    {
        int idx = hashFunction(key);

        Node *newNode = new Node(key, val);

        newNode->next = table[idx];
        table[idx] = newNode;

        currSize++;

        double labmda = currSize / (double)totalSize;
        if (labmda > 1)
        { // threshold
            rehash();
        }
    }

    bool isExist(string key)
    {
        int idx = hashFunction(key);

        Node *temp = table[idx];
        while (temp != NULL)
        {
            if (temp->key == key)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    int search(string key)
    {
        int idx = hashFunction(key);

        Node *temp = table[idx];
        while (temp != NULL)
        {
            if (temp->key == key)
            {
                return temp->val;
            }
            temp = temp->next;
        }
        return -1;
    }

    void print(){
        for (int i = 0; i < totalSize; i++)
        {
            cout << "index " << i << " -> ";
            Node* temp = table[i];
            while (temp != NULL)
            {
                cout << "( " << temp->key << ", " << temp->val << " ) -> ";
                temp = temp->next;
            }
            cout << endl;
        }
        
    }

    void remove(string key){
        int idx = hashFunction(key);

        Node* temp = table[idx];
        Node* prev = temp;

        while (temp!= NULL)
        {
            if(temp->key == key){
                if(prev == temp){
                    table[idx] = temp->next;
                } else{
                    prev->next = temp->next;
                }
                break;
            }
            prev = temp;
            temp = temp->next;
        }
        
    }
};

int main()
{
    HashTable ht(4);
    string key = "xyz";

    ht.insert("kartik", 22);
    ht.insert("soni", 18);
    ht.insert("ji", 12);
    ht.insert("abc", 5);
    ht.insert("xyz", 67);
    ht.insert("pqr", 69);

    ht.print();
    cout << "\n-----------------\n";
    ht.remove(key);
    ht.print();
    return 0;
}