// 208.实现 Trie (前缀树)

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class TrieNode {
public:
    int pass;  // 记录有多少个单词经过当前节点
    int end;   // 记录当前有多少个单词以这个节点结尾
    TrieNode* nexts[26];
};

class Trie {
private:
    TrieNode* root;
public:

    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        if (word == "") return;
        TrieNode* node = root;
        node->pass++;
        for (char ch : word){
            int index = ch - 'a';
            if (node->nexts[index] == nullptr){
                node->nexts[index] = new TrieNode();
            }
            node = node->nexts[index];
            node->pass++;
        }
        node->end++;
    }
    
    bool search(string word) {
        if(word.empty())  return false;
        TrieNode* node = root;
        for(char ch : word){
            int index = ch - 'a';
            if(node->nexts[index] == nullptr) return false;
            node = node->nexts[index];
        }
        return node->end != 0;
    }
    
    bool startsWith(string prefix) {
        if (prefix.empty()) return false;
        TrieNode* node = root;
        for(char ch : prefix){
            int index = ch - 'a';
            if(node->nexts[index] == nullptr) return false;
            node = node->nexts[index];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */