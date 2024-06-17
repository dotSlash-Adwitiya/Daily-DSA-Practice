                      
#include <bits/stdc++.h> 

using namespace std;


struct Node {

  Node* links[26];
  int cntEndWith = 0;
  int cntPrefix = 0; 

  bool containsKey(char ch) {
    return (links[ch - 'a'] != NULL); 
  }

  Node* get(char ch) {
    return links[ch - 'a']; 
  }

  void put(char ch, Node* node) {
    links[ch - 'a'] = node;
  }

  void increaseEnd() {
    cntEndWith++; 
  }

  void increasePrefix() {
    cntPrefix++;
  }

  void deleteEnd() {
    cntEndWith--; 
  }

  void reducePrefix() {
    cntPrefix--; 
  }
};

class Trie {
  private:

  Node* root; 

  public:

  Trie() {
    root = new Node(); 
  }

  void insert(string word) {
    
    Node* node = root; 
    for (int i = 0; i < word.size(); i++) { 
        if (!node->containsKey(word[i])) {
            // * Create a new node for this character
            node->put(word[i], new Node()); 
        }
          // * Move to the child node corresponding to the character
        node = node->get(word[i]);
        // * Increment the prefix count for the node
        node->increasePrefix(); 
    }
    node->increaseEnd(); 
  }

  int countWordsEqualTo(string word) {
    Node* node = root;
    // Iterate over each character in the word
    for (int i = 0; i < word.size(); i++) { 
        if (node->containsKey(word[i])) 
            node = node->get(word[i]); 
        else 
            return 0;
    }

    return node->cntEndWith; 
  }

  int countWordsStartingWith(string word) {
    Node* node = root;
    for (int i = 0; i < word.size(); i++) { 
        if (node->containsKey(word[i])) 
            // * Move to the child node corresponding to the character
            node = node->get(word[i]); 
          else 
            return 0; 
    }
    // * Return the count of words with the prefix
    return node->cntPrefix; 
  }

  void erase(string word) {

    Node* node = root;

    for (int i = 0; i < word.size(); i++) { 
        // * If the character is found in trie
        if (node->containsKey(word[i])) { 
              // * Move to the child node
              // * corresponding to the character
            node = node->get(word[i]);
            // Decrement the prefix
            node->reducePrefix(); 
        } else return; 
        
    }
    node->deleteEnd(); 
  }
};