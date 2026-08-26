#include<iostream>
#include<queue>
#include<vector>
#include<map>
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
{
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

void bottomView(Node* root){
    queue<pair<Node*, int>> q; //(Node, HD)
    map<int, int> m; // (HD, node->data)

    q.push({root, 0});

    while(!q.empty()){
        pair<Node*, int> curr = q.front();
        q.pop();

        Node* currNode = curr.first;
        int currHD = curr.second;

        m[currHD] = currNode->data;

        if(currNode->left != NULL){
            q.push({currNode->left, currHD-1});
        }

        if(currNode->right != NULL){
            q.push({currNode->right, currHD+1});
        }
    }

    for(auto &i : m){
        cout << i.second << " ";
    }
}

int main()
{
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node *root = createTree(nodes);

    bottomView(root);
    return 0;
}