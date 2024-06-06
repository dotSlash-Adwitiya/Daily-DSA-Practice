#include <bits/stdc++.h>
using namespace std;

bool detect(int src, vector<int> adj[], vector<int> &vis){
    // * Below is initial Configuration
    vis[src] = 1;
    queue<pair<int,int>> q;
    q.push({src, -1});
    
    // * BFS Start
    while(!q.empty()){
        int node = q.front().first;
        int parentNode = q.front().second;
        q.pop();
        
        for(auto adjNode : adj[node]){
            if(!vis[adjNode]){
                vis[adjNode] = 1;
                q.push({adjNode, node});
            }else if(adjNode != parentNode) {
                return true;
            }
        }
    }
    // * BFS END
    return false;
}


bool isCycle(int V, vector<int> adj[]) {
    vector<int> vis(V,0);

    // * We need to iterate over every COMPONENT
    // * Thats why we use a for loop here!
    for(int i = 0; i < V; i++) 
        if(!vis[i] && detect(i, adj, vis))
            return true;
    
    return false;    
}