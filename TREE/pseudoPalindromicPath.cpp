/*
 * Given a binary tree where node values are digits from 1 to 9.
 * A path in the binary tree is said to be pseudo-palindromic 
 * if at least one permutation of the node values in the path is a palindrome.
 * Return the number of pseudo-palindromic paths going 
 * from the root node to leaf nodes.
 *
*/


#include<bits/stdc++.h>
using namespace std;

struct Node
{
  Node* left;
  int val;
  Node* right;
};

//* HINT --->> You only need to figure out when a palindrome can be made ??
//* PATH : Definition of path is ----->>  ****ROOT to LEAF****
//* CASE : There can be at most 1 digit with odd frequency.

void helper(Node* root, vector<int> &freq, int &cnt) {
  if(root == NULL)
  return;

  //* As soon as we reach leaf, this is called a PATH.
  if(root->left == NULL && root->right == NULL) {
      
      freq[root->val]++;

      // * Check if some element exists of odd frequency.
      int oddParity = 0;
      for(int i = 0; i < 10; i++) {
          if(freq[i] & 1)
            oddParity++;
      }

      // * If there's single or no element of odd frequency, then 
      // * there definetly exists a PATH !
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