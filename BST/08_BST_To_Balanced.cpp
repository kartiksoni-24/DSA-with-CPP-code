#include <iostream>
#include<vector>
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

void inorder(Node *root, vector<int>& vec)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left, vec);
    vec.push_back(root->data);
    inorder(root->right, vec);
}

Node* BSTToBalanced(vector<int>& vec, int st, int ed){
    if(st > ed){
        return NULL;
    }

    int mid = st + (ed-st)/2;
    Node* curr = new Node(vec[mid]);

    curr->left = BSTToBalanced(vec, st, mid-1);
    curr->right = BSTToBalanced(vec, mid+1, ed);

    return curr;
}

Node* balancedBST(Node* root){
    vector<int> vec;
    inorder(root, vec);

    return BSTToBalanced(vec, 0, vec.size()-1);
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
    int arr[] = {4, 2, 6, 8, 1, 9, 0};

    Node *root = buildBST(arr, 7);
    preorder(root);
    root = balancedBST(root);
    cout << endl;
    preorder(root);
    return 0;
}