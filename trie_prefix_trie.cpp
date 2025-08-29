#include <unordered_map>
#include <string>
class TrieNode {
public:
    std::unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode(){
        isEndOfWord = false;
    }
};

class PrefixTree {
private:
    TrieNode* root;
public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for(char c : word){
            if(!node->children.count(c)){
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->isEndOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for(char c : word){
            if(!node->children.count(c)){
                return false;
            }
            node = node->children[c];
        }
        return node->isEndOfWord;
        
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(char c : prefix){
            if(!node->children.count(c)){
                return false;
            }
            node = node->children[c];
        }
        return true;
    }
};
