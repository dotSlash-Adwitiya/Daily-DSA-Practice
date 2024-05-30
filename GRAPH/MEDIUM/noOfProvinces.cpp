#include<bits/stdc++.h>
using namespace std;

// * P.S No need of adding elements to the DFS Array
/*
  * 1. Convert the Adjacency Matrix to List
  * 2. Figure out which traversal we need
  * 3. DFS or BFS Both will work, because we only need to count the connected components
  * 4. For each connected component, if we've already visited the node, we will NOT Traverse again on it!
  * 5. NOTE: if V (no of nodes not given, then it is = adjacencyMatrix.size())
*/
void dfsFn(vector<int> &vis, vector<int> adj[], int node){
    vis[node] = 1;
    
    for(int ele: adj[node]){
        if(!vis[ele])
            dfsFn(vis, adj, ele);
    }
}

int numProvinces(vector<vector<int>> adj, int V) {

    // * 5. V = adj.size();
    int provinces = 0;
    
    // * Conversion of Matrix to List
    vector<int> adjList[V]; // * 1.
    for (int i = 0; i < V; i++){
        for (int j = 0; j < V; j++){
            if(adj[i][j] == 1 && i != j){
                adjList[i].push_back(j);
                adjList[j].push_back(i);
            }
        }
    }
    
    vector<int> vis(V,0);

    for(int i = 0; i < V; i++){
        if(!vis[i]){ // * 4.
            dfsFn(vis, adjList, i); // * 3. Calling DFS|BFS for each 
            provinces++;
        }
    }
    
    return provinces;
}