#include <bits/stdc++.h>
using namespace std;


int numberOfEnclaves(vector<vector<int>> &grid) {
  queue<pair<int,int>> q; 
  int n = grid.size(); 
  int m = grid[0].size(); 
  int vis[n][m] = {0}; 

  for(int i = 0;i<n;i++) {
      for(int j = 0;j<m;j++) {
 
          if(i == 0 || j == 0 || i == n-1 || j == m-1) {

              if(grid[i][j] == 1) {
                  q.push({i, j}); 
                  vis[i][j] = 1; 
              }
          }
      }
  }
  
  int delrow[] = {-1, 0, +1, 0};
  int delcol[] = {0, +1, +0, -1}; 
  
  while(!q.empty()) {
      int row = q.front().first; 
      int col = q.front().second; 
      q.pop(); 

      for(int i = 0;i<4;i++) {
          int nrow = row + delrow[i];
          int ncol = col + delcol[i]; 

          if(nrow >=0 && nrow < n && ncol >= 0 && ncol < m 
          && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1) {
              q.push({nrow, ncol});
              vis[nrow][ncol] = 1; 
          }
      }
      
  }
  
  int cnt = 0;
  for(int i = 0;i<n;i++) {
      for(int j = 0;j<m;j++) {

          if(grid[i][j] == 1 & vis[i][j] == 0) 
              cnt++; 
      }
  }
  return cnt; 
}

// * PRACTICE - 1 
int numberOfEnclaves(vector<vector<int>> &grid) {
    // * Initial Config START
    // * STEP - 1: Create a VIS matrix
    queue<pair<int, int>> q;
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> vis(n, vector<int> (m, 0));
    
    // * STEP - 2: Mark all boundary lands as visited and put in the queue
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(i == 0 || j == 0 || i == n-1 || j == m-1) {
                if(grid[i][j] == 1){ //  * if this is a land at boundary
                    q.push({i,j});
                    vis[i][j] = 1;
                }
            }
        }
    }
    // * Initial Config END
    
    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        
        q.pop();
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};
        
        for(int i = 0; i < 4; i++) {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            
            if(nrow < n && nrow >= 0 && ncol < m && ncol >= 0 && grid[nrow][ncol] && !vis[nrow][ncol]){
                q.push({nrow, ncol});
                vis[nrow][ncol] = 1;
            }
        }
    }
    int enclaves = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] && !vis[i][j])
                enclaves++;
        }
    }
    return enclaves;
}

void dfs(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &vis, int n, int m) {
    
    if(row >= n || row < 0 || col < 0 || col >= m || grid[row][col] == 0)
        return;
        
    int delRow[] = {-1, 0, +1, 0};
    int delCol[] = {0, +1, 0, -1};
    
    // * MARK The current Cell as 0
    grid[row][col] = 0;
    
    for(int i = 0; i < 4; i++) {
        int nrow = row + delRow[i];
        int ncol = col + delCol[i];
        
        dfs(nrow, ncol, grid, vis, n, m);
    }

}

// * 2nd Approach using DFS    
int numberOfEnclaves(vector<vector<int>> &grid) {
    // * Initial Config START
    // * STEP - 1: Create a VIS matrix
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> vis(n, vector<int> (m, 0));
    // * Initial Config END
    
    // * STEP - 2: Mark all boundary lands as visited recursively using DFS
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(i == 0 || j == 0 || i == n-1 || j == m-1) {
                if(grid[i][j] == 1 && !vis[i][j]){ //  * if this is a BOUNDARY LAND which is not visited
                    dfs(i, j, grid, vis, n, m);
                }
            }
        }
    }
    
    int enclaves = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] && !vis[i][j])
                enclaves++;
        }
    }
    return enclaves;
}