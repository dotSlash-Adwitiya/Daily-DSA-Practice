#include<bits/stdc++.h>
using namespace std;

// * INTUITION : Map all the 2D indices to a hypothetical (not physical) 1D Array
// * Then, for ROW Index : 
// * We need to figure out how many rows are left behind.
// * Coz, every row will contain m elements. Where m = columns in our matrix
// * Then, for COLUMN Index :
// * We need to figure our how many row are left behind, along with additional elements to reach the current index.
// * Note that, 1st element of every row will be a multiple of m. Where m = columns in our MATRIX. 

// * TC " O(log m*n)"
//* To only check if the element exists.
bool binSearch(vector<vector<int>> &matrix, int key) {

  int low = 0, high = matrix.size()*matrix[0].size() - 1;

  while(low <= high){
    int mid = low+(high-low)/2;
    int row = mid/high;
    int col = mid%high;

    if(matrix[row][col] == key)
      return true;
    else if(matrix[row][col] < key)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return false;
}

//* To find the index
vector<int> binSearchIdx(vector<vector<int>> &matrix, int key) {

  int n = matrix.size();
  int m = matrix[0].size();
  int low = 0, high = n*m - 1;

  while(low <= high){
    int mid = low+(high-low)/2;
    int row = mid / m;
    int col = mid % m;

    if(matrix[row][col] == key)
      return {row,col};

    else if(matrix[row][col] < key)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return {-1,-1};
}

bool binSearch1DArray(vector<int> &arr, int key , int n) {
  //* n = column size of 2D array. 
  //* Becoz, every row is treated as a single 1D Array.
  int low = 0;
  int high = n-1;

  while(low <= high){
    int mid = low + (high - low) / 2;
    if(arr[mid] == key)
      return true;
    else if(arr[mid] < key)
      low = mid + 1;
    else 
      high = mid - 1;
  }
  return false;
}

// * More Optimisde Approach : O((log M) +(log N))
bool binSearchOptimised(vector<vector<int>> &matrix, int key) {
  
  int row = matrix.size();
  int col = matrix[0].size();
  int low = 0;
  int high = col - 1;

  while(low <= high) {
    int mid = low +(high - low) / 2;
    
    //* Simply check if the element lies in current ROW
    // * If yes, search in this row. Else apply binary search on remaining rows
    if(key >= matrix[mid][0] && key <= matrix[mid][col-1])
      return binSearch1DArray(matrix[mid], key, col);

    else if(matrix[mid][0] < key)
      low = mid + 1;
    
    else 
      high = mid - 1;
  }
  return false;
}


int main()
{
  vector<vector<int>> matrix {{1,2,3},
                              {4,5,6},
                              {7,8,9}};

  vector<int> ans = binSearchIdx(matrix, 4);

  // cout << "[" << ans[0] << "]" << "[" << ans[1] << "]" << endl;

  // * Optimised Bin Search Call : -
  cout << "Optimised Bin Search : " << binSearchOptimised(matrix, 9) << endl;
  return 0;
}