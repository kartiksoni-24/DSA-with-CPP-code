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

Node *balancedTreeFromSorted(vector<int>& arr, int st, int ed)
{
    if (st > ed)
    {
        return NULL;
    }

    int mid = st + (ed - st) / 2;
    Node *currNode = new Node(arr[mid]);

    currNode->left = balancedTreeFromSorted(arr, st, mid - 1);
    currNode->right = balancedTreeFromSorted(arr, mid + 1, ed);

    return currNode;
}

int kthSmallest(Node *root, int& i, int k)
{
    if (root == NULL)
    {
        return -1;
    }

    int leftRes = kthSmallest(root->left, i, k);
    if(leftRes != -1){
        return leftRes;
    }
    i++;
    if(i == k){
        return root->data;
    }

    return kthSmallest(root->right, i, k);
}

int main()
{
    vector<int> nodes = {3, 4, 5, 6, 7, 8, 9};
    Node *root = balancedTreeFromSorted(nodes, 0, nodes.size() - 1);
    int i = 0;

    cout << kthSmallest(root, i, 6);
    return 0;
}