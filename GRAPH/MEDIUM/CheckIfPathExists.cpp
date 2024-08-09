#include<bits/stdc++.h>
using namespace std;

bool is_Possible(vector<vector<int>>& grid) 
{
  int n=grid.size();
  int m=grid[0].size();
  vector<vector<int>> vis(n,vector<int>(m,0));
  queue<pair<int,int>>q;
  
  for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
          if(grid[i][j]==1){
              q.push({i,j});
              vis[i][j]=1;
          }
      }
  }
  
  int delrow[]={1,0,-1,0};
  int delcol[]={0,1,0,-1};
  
  while(!q.empty()){
      int row=q.front().first;
      int col=q.front().second;
      q.pop();
      
      if(grid[row][col]==2) return true;
      
      for(int i=0;i<4;i++){
          int nrow = row + delrow[i];
          int ncol = col + delcol[i];
          if(nrow >= 0 and nrow < n and ncol >= 0 and ncol < m and grid[nrow][ncol] != 0
          and !vis[nrow][ncol]){
              q.push({nrow,ncol});
              vis[nrow][ncol]=1;
          }
      }
  }
  return false;
}