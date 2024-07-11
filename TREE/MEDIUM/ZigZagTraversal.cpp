#include<bits/stdc++.h>
using namespace std;

struct Node{
  Node * left;
  int data;
  Node * right;
  Node(int val) {
        data = val;
        left = right = NULL;
    }
};

vector <int> zigZagTraversal(Node* root)
{
  queue<Node*> q;
  q.push(root);
  q.push(NULL);
  vector<int> temp, ans;
  int cnt = 1;
  
  while(!q.empty()) {
      Node* node = q.front();
      q.pop();
      if(node) {
          temp.push_back(node->data);
          if(node->left)
              q.push(node->left);
          if(node->right)
              q.push(node->right);
      } else {
          if(!q.empty())
              q.push(NULL);
          if(cnt % 2){
              int i = 0;
              while(i < temp.size()){
                  ans.push_back(temp[i]);
                  i++;
              }
          }
          else{
              int j = temp.size()-1;
              while(j >= 0){
                  ans.push_back(temp[j]);
                  j--;
              }
          }
          temp.clear(); // RESET Temp<>
          cnt++;
      }
  }
  return ans;
}