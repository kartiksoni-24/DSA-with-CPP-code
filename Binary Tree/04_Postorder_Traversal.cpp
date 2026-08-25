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

static int i = -1;

Node *createTree(vector<int> nodes)
{
    i++;
    if (nodes[i] == -1)
    {
        return NULL;
    }
    Node *currNode = new Node(nodes[i]);
    currNode->left = createTree(nodes);
    currNode->right = createTree(nodes);

    return currNode;
}

// Postorder = Left -> Right -> Root
void postorder(Node *root)
{ // O(n)
    if (root == NULL)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main()
{
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node *root = createTree(nodes);

    postorder(root);
    return 0;
}