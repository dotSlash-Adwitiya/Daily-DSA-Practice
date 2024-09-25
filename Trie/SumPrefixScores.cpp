#include<bits/stdc++.h>
using namespace std;

// * PROBLEM LINK:
// * https://leetcode.com/problems/sum-of-prefix-scores-of-strings/description/?envType=daily-question&envId=2024-09-25

// * BRUTE FORCE APPROACH
vector<int> sumPrefixScores(vector<string>& words) {
  int n = words.size();
  vector<int> result(n, 0);

  for (int i = 0; i < n; i++) {
      string currWord = words[i];
      for (int p = 1; p <= currWord.size(); p++) {
          string prefix = currWord.substr(0, p);
          int cnt = 0;
          for (int j = 0; j < n; j++) {
              string word = words[j];
              if (word.substr(0, p) == prefix) 
                  cnt++;
          }
          result[i] += cnt;
      }
  }
  return result;
}

// * OPTIMAL using TRIE

struct TrieNode {
  unordered_map<char, TrieNode*> children;
  int prefixCount = 0;
};

class Trie {
public:
  TrieNode* root;
  
  Trie() {
      root = new TrieNode();
  }
  
  void insert(const string& word) {
      TrieNode* node = root;
      for (char c : word) {
          if (!node->children.count(c)) {
              node->children[c] = new TrieNode();
          }
          node = node->children[c];
          node->prefixCount++; // Increment prefix count for each character
      }
  }
  
  int getPrefixScore(const string& word) {
      TrieNode* node = root;
      int score = 0;
      for (char c : word) {
          if (!node->children.count(c)) break;
          node = node->children[c];
          score += node->prefixCount;
      }
      return score;
  }
};

vector<int> sumPrefixScores(vector<string>& words) {
  Trie trie;
  for (const string& word : words) {
      trie.insert(word);
  }
  
  vector<int> result;
  for (const string& word : words) {
      result.push_back(trie.getPrefixScore(word));
  }
  
  return result;
}