#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class Node{
    public:
    unordered_map<char, Node*> children;
    bool isEnd;

    Node(){
        isEnd = false;
    }
};

class Trie{
    Node* root;
public:
    Trie(){
        root = new Node();
    }

    void insert(string key){ // O(n*l)
        Node* temp = root;

        for(int i = 0; i < key.size(); i++){
            if(temp->children.count(key[i]) == 0){
                temp->children[key[i]] = new Node();
            }
            temp = temp->children[key[i]];
        }
        temp->isEnd = false;
    }
};

int main(){
    vector<string> words = {"the", "a", "there", "their", "thee", "any"};
    Trie trie;

    for(int i = 0; i<words.size(); i++){
        trie.insert(words[i]);
    }

    return 0;
}