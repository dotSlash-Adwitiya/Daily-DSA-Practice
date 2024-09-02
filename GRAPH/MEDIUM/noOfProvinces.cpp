#include<bits/stdc++.h>
using namespace std;

// * P.S No need of adding elements to the DFS Array
/*
  * 1. Convert the Adjacency Matrix to List
  * 2. Figure out which traversal we need
  * 3. DFS or BFS Both will work, because we only need to count the connected components
  * 4. For each connected component, if we've already visited the node, we will NOT Traverse again on it!
  * 5. NOTE: if V (no of nodes not given, then it is = adjacencyMatrix.size())
  * 6. T.C : O(N) + O(V+2E), where N = No of Connected Components + DFS T.C
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

    // * T.C : O(N) + O(V+2E)
    for(int i = 0; i < V; i++){
        if(!vis[i]){ // * 4.
            dfsFn(vis, adjList, i); // * 3. Calling DFS|BFS for each 
            provinces++;
        }
    }
    
    return provinces;
}

// * BFS Approach :-
void bfs(int i,vector<vector<int>> adj,int V,vector<int> &v) {
    queue<int> q;
    q.push(i);
    v[i]=1;
    
    while(!q.empty()) {
        int top = q.front();
        q.pop();
        int cnt=0;
        for(auto it : adj[top]) {
            if(!v[cnt]&&it==1) {
                v[cnt] = 1;
                q.push(cnt);
            }
            cnt++;
        }
    }
}

int numProvinces(vector<vector<int>> adj, int V) {
    
    int ans = 0;
    vector<int> v(V,0);
    for(int i=0;i<V;i++) {
        if(!v[i]) {
            bfs(i,adj,V,v);
            ans++;
        }
    }
    return ans;
}

// * No of Provinces - Practice - 1;
void bfs(int i,vector<vector<int>> adj,int V,vector<int> &v) {
    queue<int> q;
    q.push(i);
    v[i]=1;
    
    while(!q.empty()) {
        int top = q.front();
        q.pop();
        int cnt=0;
        for(auto it : adj[top]) {
            if(!v[cnt]&&it==1) {
                v[cnt] = 1;
                q.push(cnt);
            }
            cnt++;
        }
    }
}

int numProvinces(vector<vector<int>> adj, int V) {
    
    int ans = 0;
    vector<int> v(V,0);
    for(int i=0;i<V;i++) {
        if(!v[i]) {
            bfs(i,adj,V,v);
            ans++;
        }
    }
    return ans;
}