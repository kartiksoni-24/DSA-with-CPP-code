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

bool isSame(Node *root1, Node *root2)
{
    if(root1 == NULL && root2 == NULL){
        return true;
    } else if(root1 == NULL || root2 == NULL){
        return false;
    }

    if(root1->data != root2->data){
        return false;
    }

    return isSame(root1->left, root2->left) && isSame(root1->right, root2->right);
}

bool isSubtree(Node *root, Node *subRoot)
{
    if (root == NULL && subRoot == NULL)
    {
        return true;
    }
    else if (root == NULL || subRoot == NULL)
    {
        return false;
    }

    if (root->data == subRoot->data)
    {
        if(isSame(root, subRoot)){
            return true;
        }
    }

    if (!isSubtree(root->left, subRoot))
    {
        return isSubtree(root->right, subRoot);
    }

    return true;
}

int main()
{
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node *root = createTree(nodes);

    Node* subRoot = new Node(2);
    subRoot->left = new Node(4);
    subRoot->right = new Node(5);

    if(isSubtree(root, subRoot)){
        cout << "True";
    } else{
        cout << "False";
    }
    return 0;
}