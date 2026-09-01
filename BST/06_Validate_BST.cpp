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

bool helper(Node* root, Node* min, Node* max){
    if(root == NULL){
        return true;
    }

    if(min != NULL && root->data < min->data){
        return false;
    }

    if(max != NULL && root->data > max->data){
        return false;
    }

    return helper(root->left, min, root) && helper(root->right, root, max);
}

bool isBST(Node* root){
    return helper(root, NULL, NULL);
}

int main()
{
    int arr[] = {4, 2, 6, 8, 1, 9, 0};

    Node *root = buildBST(arr, 7);

    root->data = 15;
    cout << (isBST(root) ? "true" : "false");
    return 0;
}