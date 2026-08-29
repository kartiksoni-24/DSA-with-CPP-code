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

bool helper(Node* root, int rootVal){
    if(root == NULL){
        return true;
    }

    if(root->data != rootVal){
        return false;
    }

    if(helper(root->left, rootVal)){
        return helper(root->right, rootVal);
    }

    return false;
}

bool isUnivalued(Node* root){
    int rootval = root->data;
    return helper(root, rootval);
}

int main()
{
    // vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    vector<int> nodes = {1, 1, 1, -1, -1, 1, -1, -1, 1, -1, -1};
    Node *root = createTree(nodes);

    if(isUnivalued(root)){
        cout << "True";
    } else{
        cout << "False";
    }
    return 0;
}