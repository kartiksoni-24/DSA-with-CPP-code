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
        isEnd = true;
    }
};

class Trie{
    Node* root;
    public:
    Trie(){
        root = new Node();
    }

    void insert(string key){
        Node* temp = root;

        for(int i = 0; i < key.size(); i++){
            if(temp->children.count(key[i]) == 0){
                temp->children[key[i]] = new Node();
            }
            temp = temp->children[key[i]];
        }
        temp->isEnd = true;
    }

    bool search(string key){
        Node* temp = root;

        for(int i = 0; i < key.size(); i++){
            if(temp->children.count(key[i])){
                temp = temp->children[key[i]];
            } else{
                return false;
            }
        }

        return temp->isEnd;
    }
};

bool helper(Trie &trie, string key){
    if(key.size() == 0){
        return true;
    }

    for(int i = 0; i < key.size(); i++){
        string first = key.substr(0, i+1);
        string second; 
    }
}

void wordBreak(vector<string> dict, string key){
    Trie trie;

    for(int i = 0; i < dict.size();i++){
        trie.insert(dict[i]);
    }


}

int main(){
    vector<string> words = {"the", "a", "there", "their", "thee", "any"};
   

    return 0;
}