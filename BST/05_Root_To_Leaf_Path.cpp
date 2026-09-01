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

void print(vector<int> vec){
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}

vector<int> path;

void rootToLeafPath(Node* root){
    if(root == NULL){
        return;
    }
    path.push_back(root->data);
    if(root->left == NULL && root->right == NULL){
        print(path);
    } else{
        if(root->left != NULL){
            rootToLeafPath(root->left);
        }
        if(root->right != NULL){
            rootToLeafPath(root->right);
        }
    }

    path.pop_back();
}

int main()
{
    int arr[] = {8,5,3,1,4,6,10,11,14};

    Node *root = buildBST(arr, 9);
    rootToLeafPath(root);
    return 0;
}