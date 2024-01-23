#include<bits/stdc++.h>
using namespace std;

class Node {
  public : 
    Node* left;
    int key;
    Node* right;
  public : 
    Node(int data) {
      this->left = NULL;
      this->key = key;
      this->right = NULL;
    }
  friend class Tree;
};

class Tree {
  public :

  void dfs(vector<vector<int>> &paths, vector<int> &v, Node* root, int totSum, int currSum);
  vector<vector<int>> printPaths(Node *root, int sum);
};


void Tree::dfs(vector<vector<int>> &paths, vector<int> &v, Node* root, int totSum, int currSum) {
  if(!root)
      return;
  
  // Include it first.
  currSum += root->key;
  v.push_back(root->key);
  
  if(currSum == totSum) 
      paths.push_back(v);
  
  dfs(paths, v, root->left, totSum, currSum);
  dfs(paths, v, root->right, totSum, currSum);
  
  // Exclude while returning.
  currSum -= root->key;
  v.pop_back();
}

vector<vector<int>> Tree::printPaths(Node *root, int sum)
{
  vector<vector<int>> paths;
  vector<int> v;
  dfs(paths, v, root, sum, 0);
  
  return paths;
  
}