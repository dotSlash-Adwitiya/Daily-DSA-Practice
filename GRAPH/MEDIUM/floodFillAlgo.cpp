#include<bits/stdc++.h>
using namespace std;
void dfs(int row, int col, vector<vector<int>>&ans,
  vector<vector<int>>& image, int newColor, int delRow[], int delCol[],
  int iniColor) {
    // paint with new color
    ans[row][col] = newColor; 
    int n = image.size();
    int m = image[0].size(); 

    // there are exactly 4 neighbours
    for(int i = 0;i<4;i++) {
        int nrow = row + delRow[i]; 
        int ncol = col + delCol[i]; 
        
        // check for valid coordinate 
        // then check for same initial color and unvisited pixel
        if(nrow>=0 && nrow<n && ncol>=0 && ncol < m && 
        image[nrow][ncol] == iniColor && ans[nrow][ncol] != newColor) {
            dfs(nrow, ncol, ans, image, newColor, delRow, delCol, iniColor); 
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>>& image, 
int sr, int sc, int newColor) {
    // initial color configuration
    int iniColor = image[sr][sc]; 
    vector<vector<int>> ans = image; 

    // delta row and delta column for neighbours
    int delRow[] = {-1, 0, +1, 0};
    int delCol[] = {0, +1, 0, -1}; 
    dfs(sr, sc, ans, image, newColor, delRow, delCol, iniColor); 
    return ans; 
}

int main(){
		
	vector<vector<int>>image{
	    {1,1,1},
	    {1,1,0},
	    {1,0,1}
	};
	
	vector<vector<int>> ans = floodFill(image, 1, 1, 2);
	for(auto i: ans){
		for(auto j: i)
			cout << j << " ";
		cout << "\n";
	}
	
	return 0;
}


// * Practice :
bool checkValid(int i, int j, std::vector<std::vector<int>> &ans, int initialColor, int newColor){
    if(i >= 0 && i < ans.size() && j >= 0 && j < ans[0].size() && ans[i][j] == initialColor && ans[i][j] != newColor)
        return true;
    return false;
}

void dfs(vector<vector<int>> &image, vector<vector<int>> &ans, int newColor, int initialColor, int row, int col) {
    ans[row][col] = newColor;

    if(checkValid(row-1, col, ans, initialColor, newColor)){
        dfs(image, ans, newColor, initialColor, row-1, col);
    }
    if(checkValid(row, col+1, ans, initialColor, newColor)){
        dfs(image, ans, newColor, initialColor, row, col+1);
    }
    if(checkValid(row+1, col, ans, initialColor, newColor)){
        dfs(image, ans, newColor, initialColor, row+1, col);
    }
    if(checkValid(row, col-1, ans, initialColor, newColor)){
        dfs(image, ans, newColor, initialColor, row, col-1);
    }
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
   
    vector<vector<int>> ans = image;
    int initialColor = image[sr][sc];

    dfs(image, ans, newColor, initialColor, sr, sc); 
    return ans;
}

// * Practice - 2
void dfs(int row, int col, vector<vector<int>>&ans,
    vector<vector<int>>& image, int newColor, int delRow[], int delCol[],
    int iniColor) {
    // paint with new color
    ans[row][col] = newColor; 
    int n = image.size();
    int m = image[0].size(); 
    // there are exactly 4 neighbours
    for(int i = 0;i<4;i++) {
        int nrow = row + delRow[i]; 
        int ncol = col + delCol[i]; 
        // check for valid coordinate 
        // then check for same initial color and unvisited pixel
        if(nrow>=0 && nrow<n && ncol>=0 && ncol < m && 
        image[nrow][ncol] == iniColor && ans[nrow][ncol] != newColor) {
            dfs(nrow, ncol, ans, image, newColor, delRow, delCol, iniColor); 
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>>& image, 
int sr, int sc, int newColor) {
    // initial color configuration
    int iniColor = image[sr][sc]; 
    vector<vector<int>> ans = image; 

    // delta row and delta column for neighbours
    int delRow[] = {-1, 0, +1, 0};
    int delCol[] = {0, +1, 0, -1}; 
    dfs(sr, sc, ans, image, newColor, delRow, delCol, iniColor); 
    return ans; 
}