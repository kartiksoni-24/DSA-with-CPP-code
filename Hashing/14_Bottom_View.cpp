#include <iostream>
#include <vector>
#include <unordered_map>
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

void helper(Node *root, int x, int y, unordered_map<int, pair<int, int>> &m)
{
    if (root == NULL)
    {
        return;
    }

    helper(root->left, x - 1, y + 1, m);
    helper(root->right, x + 1, y + 1, m);

    if (!m.count(x))
    {
        m[x] = {y, root->data};
    }
    else if (y > m[x].first)
    {
        m[x] = {y, root->data};
    }
}

void bottomView(Node *root)
{
    unordered_map<int, pair<int, int>> m;

    helper(root, 0, 0, m);

    for (auto &i : m)
    {
        cout << i.second.second << " ";
    }
}

int main()
{
    vector<int> nodes = {
        20,
        8,
        5, -1, -1,
        3,
        10, -1, -1,
        14, -1, -1,
        22,
        -1,
        25, -1, -1};

    Node *root = createTree(nodes);

    bottomView(root);
    return 0;
}