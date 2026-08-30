#include <iostream>
#include <vector>
#include <map>
#include <string>
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

map<string, int> m;
vector<Node *> duplicates;

string duplicateSubtree(Node *root)
{
    if (root == NULL)
    {
        return "#";
    }

    string leftStr = duplicateSubtree(root->left);
    string rightStr = duplicateSubtree(root->right);

    // Use separators and proper structure to avoid ambiguity
    string ans = "(" + to_string(root->data) + "," + leftStr + "," + rightStr + ")";

    m[ans]++;

    // Record every duplicate occurrence (when count > 1)
    if (m[ans] > 1)
    {
        duplicates.push_back(root);
    }

    return ans;
}

int main()
{
    vector<int> nodes = {1, 2, 4, -1, -1, -1, 3, 2, 4, -1, -1, -1, 4, -1, -1};
    Node *root = createTree(nodes);

    duplicateSubtree(root);

    for (int i = 0; i < duplicates.size(); i++)
    {
        cout << duplicates[i]->data << " ";
    }
    return 0;
}