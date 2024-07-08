#include<bits/stdc++.h>
using namespace std;

vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
  set<pair<int, int>> st;
  vector<int> dist(V, 1e9);
  
  st.insert({0, S});
  dist[S] = 0;
  
  while(!st.empty()) {
      auto it = *(st.begin());
      int currDist = it.first;
      int node = it.second;
      st.erase(it);
      
      for(auto it : adj[node]) {
          int adjNode = it[0];
          int edgeWt = it[1];
          
          if(edgeWt + currDist < dist[adjNode]){
              //  * Erase if someone greater already exists
              if(dist[adjNode] != 1e9)
                  st.erase({dist[adjNode], adjNode});
                  
              dist[adjNode] = currDist + edgeWt;
              st.insert({dist[adjNode], adjNode});
          }
      }
  }
  return dist;
}