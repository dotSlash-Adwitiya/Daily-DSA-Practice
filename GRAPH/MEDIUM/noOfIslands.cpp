#include<bits/stdc++.h>
using namespace std;


/*
  * Step-1 : Figure out the starting point of the island i.e, the node which is == '1'
  * Step-2 : Perform a BFS/DFS Traversal to traverse all the 1s (current full island)
  * Step-3 : Mark the nodes as visited, and check in all the 8 directions
*/

// * Using DFS Traversal
void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid){
  
  // * Marking it as visited
  vis[row][col] = 1;

  int n = grid.size();
  int m = grid[0].size();


  for(int deltaRow = -1; deltaRow<=1; deltaRow++){
      for(int deltaCol = -1; deltaCol <= 1; deltaCol++){
          int nrow = row + deltaRow;
          int ncol = col + deltaCol;
          
          if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
          && !vis[nrow][ncol] && grid[nrow][ncol] == '1'){
              vis[nrow][ncol] = 1;
              // * Call for NEXT NEIGHBOUR NODES
              dfs(nrow, ncol, vis, grid);
          }
      }
  }
      
}

// * Using BFS Traversal
void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid){
  
  // * Marking it as visited
  vis[row][col] = 1;
  queue<pair<int, int>> q;
  q.push({row, col});
  
  int n = grid.size();
  int m = grid[0].size();

  while(!q.empty()){
      // * Push the current Row and Col into Queue
      int row = q.front().first;
      int col = q.front().second;
      q.pop(); // * IMP, else, it will run infinetly!!
      
      // * Optimal Approach for checking all 8 Directions
      // * O(N²) * 9 Times (At most)
      for(int deltaRow = -1; deltaRow<=1; deltaRow++){
          for(int deltaCol = -1; deltaCol <= 1; deltaCol++){
              int nrow = row + deltaRow;
              int ncol = col + deltaCol;
              
              if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
              && !vis[nrow][ncol] && grid[nrow][ncol] == '1'){
                  vis[nrow][ncol] = 1;
                  q.push({nrow, ncol});
              }
          }
      }
      
  }
  
}


int numIslands(vector<vector<char>>& grid) {
  int n = grid.size();
  int m = grid[0].size();

  // * O(n²) Space for marking visited
  vector<vector<int>> vis(n, vector<int>(m, 0));
  int cnt = 0;
  
  // * O(n²) Time for Traversing if all the cells are marked as '1
  for(int row = 0; row < n; row++){
      for(int col = 0; col < m; col++) {
        // * If this is not already, visited use it as a starting point
          if(!vis[row][col] && grid[row][col] == '1'){
              cnt++;
              bfs(row, col, vis, grid);
          }
      }
  }
  return cnt;
}