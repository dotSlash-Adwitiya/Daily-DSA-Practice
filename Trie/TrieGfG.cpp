#include<bits/stdc++.h>
using namespace std;

#define ALPHABET_SIZE 26

struct TrieNode {
  struct TrieNode *children[ALPHABET_SIZE];

  // isLeaf is true if the node represents
  // end of a word
  bool isLeaf;
};


class Solution{    
  public:
    //Function to insert string into TRIE.
    void insert(struct TrieNode *root, string key)
    {
        TrieNode * node = root;
        for(int i = 0; i < key.size(); i++){
            if(!node->children[key[i] - 'a']){
                node->children[key[i] - 'a'] = new TrieNode(); // * Put this letter in a current trie, referring to a new trie
            }
            node = node->children[key[i] - 'a']; // * Moves to the reference trie
        }
        node->isLeaf = true;
    }
    
    //Function to use TRIE data structure and search the given string.
    bool search(struct TrieNode *root, string key) 
    {
        TrieNode * node = root;
        for(int i = 0; i < key.size(); i++){
            if(!node->children[key[i] - 'a'])
              return false;
            node = node->children[key[i] - 'a']; // * Moves to the reference trie
        }    
        return node->isLeaf;
    }
};