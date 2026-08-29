#include <iostream>
#include <vector>
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

static int idx = -1;

Node *createTree(vector<int> &nodes)
{ // O(n)
    idx++;
    if (nodes[idx] == -1)
    {
        return NULL;
    }

    Node *currNode = new Node(nodes[idx]);
    currNode->left = createTree(nodes);
    currNode->right = createTree(nodes);

    return currNode;
}

Node* deleteLeaf(Node* root, int target){

    if(root == NULL){
        return NULL;
    }

    root->left = deleteLeaf(root->left, target);
    root->right = deleteLeaf(root->right, target);

    if((root->left == NULL && root->right == NULL) && root->data == target){
        delete root;
        return NULL;
    }

    return root;
}

void preorder(Node *root)
{
    if (root == NULL)
    {
        cout << -1 << " ";
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    vector<int> nodes = {1, 2, 2, -1, -1, -1, 3, -1, 2, -1, -1};
    Node *root = createTree(nodes);

    preorder(root);
    cout << endl;
    deleteLeaf(root, 2);
    preorder(root);
    return 0;
}