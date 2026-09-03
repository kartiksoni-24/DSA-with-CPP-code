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

Node *insert(Node *root, int val)
{
    if (root == NULL)
    {
        root = new Node(val);
        return root;
    }

    if (val < root->data)
    {
        root->left = insert(root->left, val);
    }
    else
    {
        root->right = insert(root->right, val);
    }

    return root;
}

Node *buildBST(int arr[], int n)
{
    Node *root = NULL;

    for (int i = 0; i < n; i++)
    {
        root = insert(root, arr[i]);
    }
    return root;
}

void deleteTree(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    deleteTree(root->left);
    deleteTree(root->right);

    delete root;
}

void preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
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

vector<int> merge(vector<int> &vec1, vector<int> &vec2)
{
    vector<int> ans;
    int i = 0, j = 0;

    while (i < vec1.size() && j < vec2.size())
    {
        if (vec1[i] >= vec2[j])
        {
            ans.push_back(vec2[j++]);
        }
        else
        {
            ans.push_back(vec1[i++]);
        }
    }

    while (i < vec1.size())
    {
        ans.push_back(vec1[i++]);
    }
    while (j < vec2.size())
    {
        ans.push_back(vec2[j++]);
    }

    return ans;
}

Node *balanceTreeFromSorted(vector<int> &vec, int st, int ed)
{
    if (st > ed)
    {
        return NULL;
    }

    int mid = st + (ed - st) / 2;
    Node *curr = new Node(vec[mid]);

    curr->left = balanceTreeFromSorted(vec, st, mid - 1);
    curr->right = balanceTreeFromSorted(vec, mid + 1, ed);

    return curr;
}

Node *merge2BST(Node *root1, Node *root2)
{
    vector<int> vec1;
    vector<int> vec2;

    inorder(root1, vec1);
    inorder(root2, vec2);

    vector<int> ans = merge(vec1, vec2);

    return balanceTreeFromSorted(ans, 0, ans.size() - 1);
}

int main()
{
    int arr1[] = {2, 1, 4};
    int arr2[] = {9, 3, 12};

    Node *root1 = buildBST(arr1, 3);
    Node *root2 = buildBST(arr2, 3);

    Node *mergedRoot = merge2BST(root1, root2);

    preorder(mergedRoot);

    deleteTree(root1);
    deleteTree(root2);
    deleteTree(mergedRoot);
    return 0;
}