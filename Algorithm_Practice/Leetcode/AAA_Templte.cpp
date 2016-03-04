#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <unordered_map> 
using namespace std;

/*

 */

class TrieNode {
public:
    char c;
    unordered_map<char, TrieNode> children;
    bool isWord;
    TrieNode() {
        isWord = false;
    }
    TrieNode(char _c) {
        c = _c;
        isWord = false;
    }
};

class WordDictionary {
public:
    TrieNode root;
    WordDictionary() {
    }
    
    // Adds a word into the data structure.
    void addWord(string word) {
        // Write your code here
        TrieNode curtNode = root;
        for (int i = 0; i < word.length(); i++) {
            if (curtNode.children.find(word[i]) == curtNode.children.end()) {
                TrieNode node(word[i]);
                curtNode.children[word[i]] = node;
                curtNode = node;
            } else {
                curtNode = curtNode.children[word[i]];
            }
            if (i == word.length() - 1) {
                curtNode.isWord = true;
            }
        }
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        // Write your code here
        TrieNode curtNode = root;
    }
    
    bool searchHelper(string word, TrieNode searchNode) {
        if (word.length() == 1) {
            if (searchNode.c == word[0] && searchNode.isWord) {
                return true;
            } else {
                return false;
            }
        }
        
        for (int i = 0; i < word.length(); i++) {
            if (word[i] != '.') {
                if (searchNode.children.find(word[i]) == searchNode.children.end()) {
                    return false;
                } else {
                    return searchHelper(word.substr(1, word.length() - 1), searchNode.children[word[i]]);
                }    
            } else {
                bool result = false;
                for (auto it = searchNode.children.begin(); 
                    it != searchNode.children.end(); it++) {
                    result = result || searchHelper(word.substr(1, word.length() - 1), it->second);
                }
                return result;
            }
        }
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");

/*

 */

