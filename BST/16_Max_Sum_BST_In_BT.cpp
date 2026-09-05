#include <iostream>
#include <vector>
#include <climits>
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

class Data
{
public:
    bool isBST;
    int min, max, sum;

    Data(bool isBST, int min, int max, int sum)
    {
        this->isBST = isBST;
        this->min = min;
        this->max = max;
        this->sum = sum;
    }
};

static int maxSum = 0;

Data* maxSumBST(Node* root){
    if(root == NULL){
        return new Data(true, INT_MAX, INT_MIN, 0);
    }

    Data* leftData = maxSumBST(root->left);
    Data* rightData = maxSumBST(root->right);

    int currMin = min(root->data, min(leftData->min, rightData->min));
    int currMax = max(root->data, max(leftData->max, rightData->max));
    int currSum = leftData->sum + rightData->sum + root->data;

    if(leftData->isBST && rightData->isBST && root->data > leftData->max && root->data < rightData->min){
        maxSum = max(maxSum, currSum);
        return new Data(true, currMin, currMax, currSum);
    }

    return new Data(false, currMin, currMax, currSum);
}

int main()
{
    vector<int> nodes = {50, 30, 5, -1, -1, 20, -1, -1, 60, 45, -1, -1, 70, 65, -1, -1, 80, -1, -1};
    Node *root = createTree(nodes);

    maxSumBST(root);
    cout << maxSum;

    return 0;
}