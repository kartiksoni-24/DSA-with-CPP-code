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

int kthAnces(Node* root, int node, int k){ // O(n)
    if(root == NULL){
        return -1;
    }

    if(root->data == node){
        return 0;
    }

    int leftDist = kthAnces(root->left, node, k);
    int rightDist = kthAnces(root->right, node, k);

    if(leftDist == -1 && rightDist == -1){
        return -1;
    }

    int validDist = leftDist == -1 ? rightDist : leftDist;
    if(validDist + 1 == k){
        cout << "Kth Ancestor : " << root->data;
    }

    return validDist+1;
}

int main()
{
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node *root = createTree(nodes);

    kthAnces(root, 6, 1);
    return 0;
}