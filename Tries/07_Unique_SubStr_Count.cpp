#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Node
{
public:
    unordered_map<char, Node *> children;
    bool isEnd;

    Node()
    {
        isEnd = false;
    }
};

class Trie
{
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(string key)
    { // O(n*l)
        Node *temp = root;

        for (int i = 0; i < key.size(); i++)
        {
            if (temp->children.count(key[i]) == 0)
            {
                temp->children[key[i]] = new Node();
            }
            temp = temp->children[key[i]];
        }
        temp->isEnd = true;
    }

    bool search(string key)
    {
        Node *temp = root;

        for (int i = 0; i < key.size(); i++)
        {
            if (temp->children.count(key[i]))
            {
                temp = temp->children[key[i]];
            }
            else
            {
                return false;
            }
        }

        return temp->isEnd;
    }

    int helper(Node* root){
        int ans = 0;
        Node* temp = root;

        for(pair<char, Node*> child : temp->children){
            ans += helper(child.second);
        }

        return ans+1;
    }

    int count(){
        return helper(root);
    }
};

int countSubStr(string word){
    Trie trie;

    string suffix = "";
    for (int i = 0; i < word.size(); i++)
    {
        suffix = word.substr(i);
        trie.insert(suffix);
    }
    return trie.count();
}

int main(){
    string str = "ababa";
    cout << countSubStr(str);

    return 0;
}