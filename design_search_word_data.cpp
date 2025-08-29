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

class WordDictionary {
private:
    TrieNode* root;
    bool searchHelp(const std::string& word, int index, TrieNode* node){
        if(index == word.size()){
            return node->isEndOfWord;
        }

        char c = word[index];
        if(c == '.'){
            for(auto& [key, child] : node->children){
                if(searchHelp(word, index + 1, child)){
                    return true;
                }
            }
            return false;
        } else {
            if(!node->children.count(c)){
                return false;
            }
            return searchHelp(word, index + 1, node->children[c]);
        }
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }
    void addWord(std::string word) {
        TrieNode* node = root;
        for(char c : word){
            if(!node->children.count(c)){
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->isEndOfWord = true;
    }
    
    bool search(std::string word) {
        return searchHelp(word, 0, root);
    }
};
