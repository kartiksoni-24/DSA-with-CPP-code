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
};

int main(){
    Trie trie;
    return 0;
}