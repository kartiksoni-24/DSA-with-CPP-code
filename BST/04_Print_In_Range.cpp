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

void printInRange(Node *root, int st, int ed)
{
    if (root == NULL)
    {
        return;
    }

    if (root->data >= st && root->data <= ed)
    {   // for sorted output call in inorder sequence
        printInRange(root->left, st, ed);
        cout << root->data << " ";
        printInRange(root->right, st, ed);
    }
    else if (root->data < st)
    {
        printInRange(root->right, st, ed);
    }
    else
    {
        printInRange(root->left, st, ed);
    }
}

int main()
{
    int arr[] = {4, 2, 6, 8, 1, 9, 0};

    Node *root = buildBST(arr, 7);
    printInRange(root, 2, 8);
    return 0;
}