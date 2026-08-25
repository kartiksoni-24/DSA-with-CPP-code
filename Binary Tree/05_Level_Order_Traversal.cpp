#include <iostream>
#include <vector>
#include<queue>
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

void levelOrder(Node* root){
    if(root == NULL){
        return;
    }

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){ // O(n)
        Node* curr = q.front();
        q.pop();

        cout << curr->data << " ";

        if(curr->left != NULL){
            q.push(curr->left);
        }

        if(curr->right != NULL){
            q.push(curr->right);
        }
    }
}

int main()
{
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node *root = createTree(nodes);

    levelOrder(root);
    return 0;
}