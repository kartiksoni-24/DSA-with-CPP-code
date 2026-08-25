#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right= NULL;
    }
};

static int i = -1;

Node* createTree(vector<int> nodes){
    i++;

    if(nodes[i] == -1){
        return NULL;
    }

    Node* currNode = new Node(nodes[i]);
    currNode->left = createTree(nodes);
    currNode->right = createTree(nodes);

    return currNode;
}

// Inorder = Left -> Root -> Right
void inorder(Node* root){ // O(n)
    if (root == NULL)
    {
        return;
    }
    
    inorder(root->left);
    cout<< root->data << " ";
    inorder(root->right);
}

int main(){
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node* root = createTree(nodes);

    inorder(root);
    return 0;
}