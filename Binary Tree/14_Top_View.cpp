#include <iostream>
#include <vector>
#include<map>
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

void topView(Node* root){
    if (root == NULL)
        return;
    
    queue<pair<Node*, int>> q;// node, horizontal distance
    map<int, int> m; // horizontal distance, node->data

    q.push({root, 0});

    while (!q.empty())
    {
        pair<Node*, int> curr = q.front();
        q.pop();

        Node* currNode = curr.first;
        int currHD = curr.second;

        if(m.count(currHD) == 0){
            m[currHD] = currNode->data;
        }

        if(currNode->left != NULL){
            pair<Node*, int> left = {currNode->left, currHD-1};
            q.push(left);
        }

        if(currNode->right != NULL){
            q.push({currNode->right, currHD + 1});
        }
    }
    
    for(auto &i:m){
        cout << i.second << " ";
    }
}

int main()
{
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node *root = createTree(nodes);

    topView(root);
    return 0;
}