#include <iostream>
#include <vector>
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

void inorder(Node *root, vector<int> &vec)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left, vec);
    vec.push_back(root->data);
    inorder(root->right, vec);
}

int twoBstSum(Node *root1, Node *root2, int target)
{
    vector<int> vec1;
    vector<int> vec2;

    inorder(root1, vec1);
    inorder(root2, vec2);

    int i = 0, j = vec2.size() - 1, count = 0;

    while (i < vec1.size() && j >= 0)
    {
        if (vec1[i] + vec2[j] < target)
        {
            i++;
        }
        else if (vec1[i] + vec2[j] > target)
        {
            j--;
        }
        else
        {
            count++;
            i++;
            j--;
        }
    }

    return count;
}

int main()
{
    int BST1[] = {2, 4, 6, 8, 10, 12, 14};
    int BST2[] = {1, 3, 5, 7, 9, 11, 13};

    Node *root1 = balancedTreeFromSorted(BST1, 0, 6);
    Node *root2 = balancedTreeFromSorted(BST2, 0, 6);

    cout << twoBstSum(root1, root2, 15);

    return 0;
}