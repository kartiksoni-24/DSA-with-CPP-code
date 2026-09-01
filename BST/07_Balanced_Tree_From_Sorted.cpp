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

Node* balancedTreeFromSorted(int arr[], int st, int ed){
    if(st > ed){
        return NULL;
    }

    int mid = st + (ed-st)/2;
    Node* currNode = new Node(arr[mid]);

    currNode->left = balancedTreeFromSorted(arr, st, mid-1);
    currNode->right = balancedTreeFromSorted(arr, mid+1, ed);
    
    return currNode;
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
    int arr[] = {3,4,5,6,7,8,9};

    Node *root = balancedTreeFromSorted(arr, 0, 6);
    preorder(root);
    return 0;
}