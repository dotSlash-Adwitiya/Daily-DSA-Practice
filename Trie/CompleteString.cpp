#include<bits/stdc++.h>
using namespace std;

struct Node {
  Node * links[26];
  bool flag = false;
  bool containsKey(char ch) {
    return (links[ch - 'a'] != NULL); // * Returns whether, at this position null exists or char ?
  }

  void put(char ch, Node* node){
    links[ch - 'a'] = node;
  }

  Node* move(char ch){
    return links[ch - 'a'];
  }

  bool setEnd() {
    flag = true;
  }

  bool isEnd(){
    return flag;
  }

};


class Trie{
  private:
    Node* root; // * EVERY TRIE Will have a root

  public:
    Trie(){
      root = new Node();
    }

    // * T.C : O(lengthOfWord)
    void insert(string word){
      Node * node = root;
      for(int i = 0; i < word.size(); i++){
          if(!node->containsKey(word[i])){
            node->put(word[i], new Node()); // * Put this letter in a current trie, referring to a new trie
          }
          node->move(word[i]); // * Moves to the reference trie
      }
      // node->flag = true;
      node->setEnd();
    }

    bool search(string word){
      Node *node = root;

      for(int i = 0; i < word.length(); i++){
        if(!node->containsKey(word[i]))
            return false;
        node = node->move(word[i]); // * Move to the reference of this letter 
      }
      return node->isEnd();
    }

    bool startsWith(string prefix){
      Node *node = root;

      for(int i = 0; i < prefix.length(); i++){
        if(!node->containsKey(prefix[i]))
            return false;
        node = node->move(prefix[i]); // * Move to the reference of this letter 
      }
      // * In this, doesn't matter if we reach the end of TRIE
      // * Because, we are searching for a PREFIX
      return true;  
    }

     bool checkIfAllPrefixExists(string word) {
        Node *node = root;
        bool flag = true; 
        for(int i = 0;i<word.size();i++) {
            if(node->containsKey(word[i])) {
                node = node->move(word[i]); 
                flag = flag & node->isEnd(); 
            }
            else {
                return false; 
            } 
        }
        return flag; 
    }
};

string completeString(int n, vector<string> &words){
  Trie *trie = new Trie();

  // * Insert Every word in a TRIE DS
  for(string word: words)
    trie->insert(word);

  string longest = "";
  for(string word: words){
    if(trie->checkIfAllPrefixExists(word)){
      if((word.size() > longest.size()) || (word.size() == longest.size() && word < longest))
        longest = word;
    }
  }
  
  if(longest == "")
    return "None";
  return longest;
}