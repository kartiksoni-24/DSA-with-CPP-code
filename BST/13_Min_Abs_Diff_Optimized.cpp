#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

Node *balancedTreeFromSorted(int arr[], int st, int ed)
{
    if (st > ed)
    {
        return NULL;
    }

    int mid = st + (ed - st) / 2;
    Node *currNode = new Node(arr[mid]);

    currNode->left = balancedTreeFromSorted(arr, st, mid - 1);
    currNode->right = balancedTreeFromSorted(arr, mid + 1, ed);

    return currNode;
}

Node* minAbsDiff(Node* root, int key){ // O(height)
    if(root == NULL){
        return NULL;
    }

    Node* best = root;

    if(key < root->data){
        best = minAbsDiff(root->left, key);
    } else if(key > root->data){
        best = minAbsDiff(root->right, key);
    } else{
        return root;
    }

    if(best != NULL && abs(best->data - key) < abs(root->data - key)){
        return best;
    }
    return root;
}

int main()
{
    int arr[] = {3, 4, 5, 6, 7, 8, 9};
    Node *root = balancedTreeFromSorted(arr, 0, 6);
   
    cout << minAbsDiff(root, 10)->data;
    return 0;
}