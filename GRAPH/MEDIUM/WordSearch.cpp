#include<bits/stdc++.h>
using namespace std;

bool dfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& board, const string& word, int index) {
  if (index == word.length()) 
      return true; // * All characters of the word are found
  
  
  int n = board.size();
  int m = board[0].size();
  vis[row][col] = 1;
  
  int delrow[] = {1, 0, -1, 0};
  int delcol[] = {0, 1, 0, -1};
  
  for (int i = 0; i < 4; i++) {
      int nrow = row + delrow[i];
      int ncol = col + delcol[i];
      
      if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && !vis[nrow][ncol] && board[nrow][ncol] == word[index]) {
          if (dfs(nrow, ncol, vis, board, word, index + 1)) {
              return true;
          }
      }
  }
  
  vis[row][col] = 0; // * Backtrack
  return false;
}

bool isWordExist(vector<vector<char>>& board, string word) {
  int n = board.size();
  int m = board[0].size();
  
  vector<vector<int>> vis(n, vector<int>(m, 0));
  
  for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
          if (board[i][j] == word[0]) {
              if (dfs(i, j, vis, board, word, 1)) {
                  return true;
              }
          }
      }
  }
  return false;
}