#include<bits/stdc++.h>
using namespace std;

bool checkValid(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &vis){
  if(row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size() && vis[row][col] == 0 && grid[row][col] == 1)
      return true;
  return false;
}

int orangesRotting(vector<vector<int>>& grid) {
  int n = grid.size();
  int m = grid[0].size();

  // * Intial Configuration START
  queue<pair<pair<int,int>, int>> q;
  vector<vector<int>> vis(n, vector<int>(m, 0));
  for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
          if(grid[i][j] == 2){
              q.push({{i,j}, 0});
              vis[i][j] = 1;
          }
          else 
              vis[i][j] = 0;
              
      }
  }
  // * Intial Configuration END
  
  
  int maxTime = 0;
  while(!q.empty()){
      int row = q.front().first.first;
      int col = q.front().first.second;
      int time = q.front().second;
      // * The newly found orange MIGHT have a differnt time, hence perform a check below
      maxTime = max(maxTime, time);
      
      q.pop();
      
      // * Alternative Logic to Delta Row & Delta Column
      if(checkValid(row - 1, col, grid, vis)) {
          q.push({{row-1, col}, time+1});
          vis[row-1][col] = 1;
      }
      if(checkValid(row, col+1, grid, vis)) {
          q.push({{row, col+1}, time+1});
          vis[row][col+1] = 1;
      }
      if(checkValid(row + 1, col, grid, vis)) {
          q.push({{row + 1, col}, time+1});
          vis[row + 1][col] = 1;
      }
      if(checkValid(row, col - 1, grid, vis)) {
          q.push({{row, col - 1}, time+1});
          vis[row][col - 1] = 1;
      }
  }
  
  for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
          if(grid[i][j] == 1 && vis[i][j] == 0)
              return -1; // * Fresh Orange Found!!
      }
  }
  return maxTime;
}