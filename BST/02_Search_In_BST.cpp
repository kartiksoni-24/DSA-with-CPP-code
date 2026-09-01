#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

Node *insert(Node *root, int val)
{
    if (root == NULL)
    {
        root = new Node(val);
        return root;
    }

    if (val < root->data)
    {
        root->left = insert(root->left, val);
    }
    else
    {
        root->right = insert(root->right, val);
    }

    return root;
}

Node *buildBST(int arr[], int n)
{
    Node *root = NULL;

    for (int i = 0; i < n; i++)
    {
        root = insert(root, arr[i]);
    }
    return root;
}

bool search(Node* root, int key){ // O(height), in avg case O(logn)
    if(root == NULL){
        return false;
    }

    if(key == root->data){
        return true;
    } else if(key < root->data){
        return search(root->left, key);
    } else{
        return search(root->right, key);
    }
}

int main()
{
    int arr[] = {4, 2, 6, 8, 1, 9, 0};

    Node *root = buildBST(arr, 7);
    cout << (search(root, 3) ? "Present" : "Not found");
    return 0;
}