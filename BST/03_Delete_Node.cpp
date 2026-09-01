#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
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

Node *buildTree(int arr[], int n)
{
    Node *root = NULL;

    for (int i = 0; i < n; i++)
    {
        root = insert(root, arr[i]);
    }
    return root;
}

Node *getInorderSuccessor(Node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

Node *delNode(Node *root, int val)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (val < root->data)
    {
        root->left = delNode(root->left, val);
    }
    else if (val > root->data)
    {
        root->right = delNode(root->right, val);
    }
    else
    { // root == val
        // val is on leaf node
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // val node only have 1 child
        if (root->left == NULL || root->right == NULL)
        {
            return root->left == NULL ? root->right : root->left;
        }

        // val node have 2 child
        Node *IS = getInorderSuccessor(root->right);
        root->data = IS->data;
        root->right = delNode(root->right, IS->data);
        return root;
    }
}

void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    int arr[] = {4, 2, 6, 5, 7, 8, 1, 9, 0};

    Node *root = buildTree(arr, 9);

    preorder(root);
    cout << endl;
    delNode(root, 4);
    preorder(root);

    return 0;
}