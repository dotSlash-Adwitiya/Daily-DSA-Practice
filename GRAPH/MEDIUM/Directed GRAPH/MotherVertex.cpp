#include<bits/stdc++.h>
using namespace std;

// * If there's a Mother VERTEX, then it WILL mark ALL the nodes as VISITED.
void dfs(int node, vector<int>adj[], vector<bool> &vis){
  vis[node] = true;
  
  for(int &currNode: adj[node]){
      if(!vis[currNode])
          dfs(currNode, adj, vis);
  }
}

int findMotherVertex(int V, vector<int>adj[])
{
vector<bool>vis(V,false);
int possible_mother_vertex;

for(int i=0;i<V;i++){
    if(!vis[i]){
        dfs(i,adj,vis);
        possible_mother_vertex = i;
    }
}

for(int i=0;i<V;i++) vis[i]=false;

// * Perform DFS AGAIN, if all nodes are marked as TRUE in the end
// * Then this is DEFINETLY the Mother VERTEX
dfs(possible_mother_vertex, adj, vis);

for(int i=0;i<V;i++)
    if(!vis[i]) return -1;

return possible_mother_vertex;
}