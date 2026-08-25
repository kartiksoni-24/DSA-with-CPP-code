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

Node *createTree(vector<int>& nodes)
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

int countNode(Node* root){ // O(n)
    if (root == NULL)
    {
        return 0;
    }
    
    int leftCount = countNode(root->left);
    int rightCount = countNode(root->right);

    int count = leftCount + rightCount + 1;

    return count;
}

int main()
{
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, 6, -1, 7, -1, -1, 3, -1, -1};
    Node *root = createTree(nodes);

    cout << countNode(root);
    return 0;
}