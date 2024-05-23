#include<bits/stdc++.h>
using namespace std;

vector<int> bfsOfGraph(int V, vector<int> adj[]) {
  
  // * Initial configuration given in questions :-

  vector<int> vis(V,0);
  queue<int> q;
  vis[0] = 1;
  q.push(0);
  
  // * Create ans bfs vector        
  vector<int> bfs;
  
  // * !q.empty() will help input the LAST Remaining element in the BFS
  while(!q.empty()){
      int node = q.front();
      q.pop();
      bfs.push_back(node);
      
      for(int ele : adj[node]){
          
          // * Put in the queue only if its already not visited
          if(!vis[ele]){
              q.push(ele);    
              vis[ele] = 1;
          }
      }
  }
  return bfs;
}