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

static int ans = 0;

int rangeSum(Node* root, int low, int high){
    if (root == NULL)
    {
        return 0;
    }
    
    if(root->data >= low){
        rangeSum(root->left, low, high);
    }
    
    if(root->data <= high){
        rangeSum(root->right, low, high);
    }

    if(low <= root->data && root->data <= high){
        ans += root->data;
    }

    return ans;
}

int main()
{
    int arr[] = {4, 2, 6, 8, 1, 9, 0};

    Node *root = buildBST(arr, 7);
    rangeSum(root, 2, 8);
    cout << ans;
    return 0;
}