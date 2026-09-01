#include <iostream>
#include <vector>
#include<climits>
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

int maxSum = INT_MIN;

int maxPathSum(Node* root){
    if(root == NULL){
        return 0;
    }

    int leftSum = maxPathSum(root->left);
    int rightSum = maxPathSum(root->right);

    maxSum = max(maxSum,root->data + leftSum + rightSum);
    int currSum = root->data + max(leftSum, rightSum);

    return currSum;
}

int main()
{
    vector<int> nodes = {-10, 9, -1, -1, 20, 15, -1, -1, 7, -1, -1};
    Node *root = createTree(nodes);

    maxPathSum(root);
    cout << maxSum;
    return 0;
}