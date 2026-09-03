#include <iostream>
#include<vector>
#include<climits>
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

class Data{
    public:
    bool isBST;
    int min, max, size;

    Data(bool isBST, int min, int max, int size){
        this->isBST = isBST;
        this->min = min;
        this->max = max;
        this->size= size;
    }
};

static int maxSize;

Data* largestBST(Node* root){ // O(n)
    if(root == NULL){
        return new Data(true, INT_MAX, INT_MIN, 0);
    }

    // alternate base case
    // if(root == NULL){
    //     return NULL;
    // }
    // if(root->left == NULL && root->right == NULL){
    //     return new Data(true, root->data, root->data, 1);
    // }

    Data* leftData = largestBST(root->left);
    Data* rightData = largestBST(root->right);

    int currMin = min(root->data, min(leftData->min, rightData->min));
    int currMax = max(root->data, max(leftData->max, rightData->max));
    int currSize = leftData->size + rightData->size + 1;

    if(leftData->isBST && rightData->isBST && root->data > leftData->max && root->data < rightData->min){
        maxSize = max(currSize, maxSize);
        return new Data(true, currMin, currMax, currSize);
    }

    return new Data(false, currMin, currMax, currSize);
}

int main()
{
    vector<int> nodes = {50,30,5,-1,-1,20,-1,-1,60,45,-1,-1,70,65,-1,-1,80,-1,-1};
    Node* root = createTree(nodes);
    
    largestBST(root);
    cout << maxSize;
  
    return 0;
}