#include<iostream>
#include<vector>
using namespace std;

//! Partially - IncorrecT CODE
void createGraphInAdjacencyMatrix(){
    int n, m;
    cin >> n >> m;
    // adjacency matrix for undirected graph
    // time complexity: O(n)
    int adj[n+1][n+1];
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;  // this statement will be removed in case of directed graph
    }

    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        if(adj[i][j] == 1)
          cout << i << j << " ";  
      }
      cout << endl;
    }
}

int main()
{
  
  createGraphInAdjacencyMatrix();
  return 0;
}