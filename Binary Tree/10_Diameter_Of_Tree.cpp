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

int hieght(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftHt = hieght(root->left);
    int rightHt = hieght(root->right);

    return max(leftHt, rightHt) + 1;
}

int diameter(Node *root) // O(n^2)
{
    if (root == NULL)
    {
        return 0;
    }

    int currDia = hieght(root->left) + hieght(root->right) + 1;
    int leftDia = diameter(root->left);
    int rightDia = diameter(root->right);

    return max(currDia, max(leftDia, rightDia));
}

int main()
{
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node *root = createTree(nodes);

    cout << "Diameter of Tree : " << diameter(root);
    return 0;
}