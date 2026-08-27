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

bool findPath(Node* root, int n, vector<int>& path){
    if(root == NULL){
        return false;
    }

    path.push_back(root->data);
    if(root->data == n){
        return true;
    }

    int left = findPath(root->left, n, path);
    int right = findPath(root->right, n, path);

    if(left || right){
        return true;
    }

    path.pop_back();
    return false;
}

int LCA(Node* root, int n1, int n2){ // O(n),O(n)
    vector<int> path1;
    vector<int> path2;

    findPath(root, n1, path1);
    findPath(root, n2, path2);

    int lca = -1;
    for(int i = 0, j = 0; i < path1.size() && j < path2.size(); i++, j++){
        if(path1[i] != path2[j]){
            return lca;
        }

        lca = path2[j];
    }

    return lca;
}

int main()
{
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node *root = createTree(nodes);

    cout << LCA(root, 5, 3);
    return 0;
}