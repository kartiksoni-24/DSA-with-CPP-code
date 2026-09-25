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

    void helper(Node* root, string& ans, string temp){
        for(pair<char, Node*> child : root->children){
            if(child.second->isEnd){
                temp += child.first;

                if((temp.size() == ans.size() && temp < ans) || (temp.size() > ans.size())){
                    ans = temp;
                }

                helper(child.second, ans, temp);
                temp = temp.substr(0, temp.size()-1);
            }
        }
    }

    string longestString(){
        string ans = "";
        helper(root, ans, "");

        return ans;
    }
};

string longestStr(vector<string>& dict)
{
    Trie trie;

    for (int i = 0; i < dict.size(); i++)
    {
        trie.insert(dict[i]);
    }

    return trie.longestString();
}

int main(){
    vector<string> dict = {"bananan", "a", "appl", "app", "apply", "ap", "apple"};
    cout << longestStr(dict);

    return 0;
}