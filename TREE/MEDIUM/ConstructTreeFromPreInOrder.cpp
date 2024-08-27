#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* constructTree(int preStart, int preEnd, int inStart, int inEnd, vector<int>& preorder, vector<int>& inorder, unordered_map<int, int> &ump){
  
  if(preStart > preEnd || inStart > inEnd) return NULL;

  TreeNode* root = new TreeNode(preorder[preStart]);
  
  int rootIdx = ump[root->val];
  int numsLeft = rootIdx - inStart;

  root->left = constructTree(preStart + 1, preStart + numsLeft, inStart, rootIdx - 1, preorder, inorder, ump);
  root->right = constructTree(preStart + numsLeft + 1, preEnd, rootIdx + 1, inEnd, preorder, inorder, ump);

  return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
  unordered_map<int, int> ump;
  for(int i = 0; i < inorder.size(); i++)
      ump[inorder[i]] = i;

  return constructTree(0, preorder.size() - 1, 0, inorder.size() - 1, preorder, inorder, ump);
}