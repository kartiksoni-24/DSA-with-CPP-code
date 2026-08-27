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

Node* LCA(Node* root, int n1, int n2){
    if(root == NULL){
        return NULL;
    }

    if(root->data == n1 || root->data == n2){
        return root;
    }

    Node* left = LCA(root->left, n1, n2);
    Node* right = LCA(root->right, n1, n2);

    if(left != NULL && right != NULL){
        return root;
    }

    return left == NULL ? right : left;
}

int dist(Node* root, int n){
    if(root == NULL){
        return -1;
    }

    if(root->data == n){
        return 0;
    }

    int leftDist = dist(root->left, n);
    if(leftDist != -1){
        return leftDist + 1;
    }

    int rightDist = dist(root->right, n);
    if(rightDist != -1){
        return rightDist + 1;
    }

    return -1;
}

int minDist(Node* root, int n1, int n2){ // O(n)
    Node* lca = LCA(root, n1, n2);

    int distLeft = dist(lca, n1);
    int distRight = dist(lca, n2);

    return distLeft + distRight;
}

int main()
{
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node *root = createTree(nodes);

    cout << minDist(root, 5, 1);
    return 0;
}