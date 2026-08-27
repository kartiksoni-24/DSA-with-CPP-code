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

void kthLevelNodes(Node* root, int k, int level){ // O(n)
    if(root == NULL){
        return;
    }
    if(level == k){
        cout << root->data << " ";
        return;
    }

    if(level < k){
    kthLevelNodes(root->left, k, level+1);
    kthLevelNodes(root->right, k, level+1);
    } else{
        return ;
    }
}

int main()
{
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node *root = createTree(nodes);

    kthLevelNodes(root, 2, 1);
    return 0;
}