#include<bits/stdc++.h>
using namespace std;

struct Node
{
  Node* left;
  int val;
  Node* right;
};


void helper(Node* root, vector<int> &freq, int &cnt) {
  if(root == NULL)
  return;

  if(root->left == NULL && root->right == NULL) {
      
      freq[root->val]++;

      int oddParity = 0;
      for(int i = 0; i < 10; i++) {
          if(freq[i] & 1)
          oddParity++;
      }
      if(oddParity < 2)
          cnt++;

      freq[root->val]--;
      return;
  }

  freq[root->val]++;


  helper(root->left, freq, cnt);
  helper(root->right, freq, cnt);

  freq[root->val]--;
}

int pseudoPalindromicPaths (Node* root) {
  vector<int> freq(10);
  int cnt = 0;
  helper(root, freq, cnt);
  return cnt;
}