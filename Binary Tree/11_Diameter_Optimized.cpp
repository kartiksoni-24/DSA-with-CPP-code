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

Node *createTree(vector<int>& nodes)
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

pair<int, int> diameter(Node*& root){ // O(n)
    if(root == NULL){
        return {0,0};
    }

    // pair = (diameter, height)
    pair<int, int> leftInfo = diameter(root->left); // (LD, LH)
    pair<int, int> rightInfo = diameter(root->right); // (RD, RH)

    int currDia = leftInfo.second + rightInfo.second + 1;
    int diameter = max(currDia, max(leftInfo.first, rightInfo.first));
    int height = max(leftInfo.second, rightInfo.second) + 1;

    return {diameter, height};
}

int main()
{
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node *root = createTree(nodes);

    cout << "Diameter : " << diameter(root).first << endl;
    cout << "Height : " << diameter(root).second;
    return 0;
}