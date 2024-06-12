#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
	bool checkValid(int nrow, int ncol, int n, int m, vector<vector<int>> &dist, vector<vector<int>> &vis){
			if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol])
					return true;
			return false;
	}
	
public:
	vector<vector<int>> nearest(vector<vector<int>>& grid) {
			
			// * Initial Configuration START
			int n = grid.size();
			int m = grid[0].size();
			
			// * Visited array
			vector<vector<int>> vis(n, vector<int>(m,0));
			
			// * Creating a separate matrix to not mess with the given data.
			vector<vector<int>> dist(n, vector<int>(m,0));
			queue<pair<pair<int,int>, int>> q;
			// * Initial Configuration END
			
			for(int i = 0; i < n; i++){
					for(int j = 0; j < m; j++) {
							if(grid[i][j] == 1){
									vis[i][j] = 1;
									q.push({{i,j},0});            
							}
							else {
									vis[i][j] = 0;
							}
					}
			}
			
			int delRow[] = {-1,0,1,0};
			int delCol[] = {0,1,0,-1};
			
			while(!q.empty()){
					int row = q.front().first.first;
					int col = q.front().first.second;
					int steps = q.front().second;
					
					// * MARKING the row and col as the stpes required 
					// * to move to this row and col
					dist[row][col] = steps;
					
					q.pop();
					
					// * Finally understood the delta logic through this question
					// * Reminder : YOU DO NOT NEED TO UNDERSTAND EVERYTHING TO MOVE FORWARD
					for(int i = 0; i < 4; i++){
							int nrow = row + delRow[i];
							int ncol = col + delCol[i];
							
							if(checkValid(nrow, ncol, n, m, dist, vis)){
									vis[nrow][ncol] = 1;
									q.push({{nrow,ncol}, steps+1});
							}
					}
			}
			return dist;    
	}
};
