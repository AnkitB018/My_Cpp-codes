#include<iostream>

using namespace std;

class Trie {
    struct Node{
        Node* children[26]= {nullptr};
        bool isleaf = false;
    };
    struct Node *root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* curr = root;
        for(char c:word){
            if(!curr->children[c-'a']){
                curr->children[c-'a'] = new Node();
            }
            curr = curr->children[c-'a'];
        }

        curr->isleaf = true;
    }
    
    bool search(string word) {
        Node* curr = root;
        for(char c:word){
            if(!curr->children[c-'a']){
                return false;
            }
            curr = curr->children[c-'a'];
        }
        if(curr->isleaf){
            return true;
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        Node* curr = root;
        for(char c:prefix){
            if(!curr->children[c-'a']){
                return false;
            }
            curr = curr->children[c-'a'];
        }
        return true;
    }
};
