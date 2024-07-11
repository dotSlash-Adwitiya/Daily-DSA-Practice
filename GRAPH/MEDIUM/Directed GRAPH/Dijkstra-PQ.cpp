#include<bits/stdc++.h>
using namespace std;

vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
  priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
  vector<int> dist(V, 0);
          
  // * Mark the distance as INFINITY Initially        
  for(int i = 0; i < V; i++)
      dist[i] = 1e9;
  
  // * Src will always be reachable at 0 distance
  dist[S] = 0;
  pq.push({0, S});
  
  
  while(!pq.empty()) {
      // * Extract The distance and its value till current node
      int nodeDist = pq.top().first;
      int node = pq.top().second;
      
      pq.pop();
      
      for(auto it: adj[node]){
          int edgeWt = it[1]; // * All other nodes from currentNode
          int adjNode = it[0];
          
          // *  If the distance of currentNode from the node is < then store it.
          if(nodeDist + edgeWt < dist[adjNode]){
              dist[adjNode] = nodeDist + edgeWt;
              pq.push({dist[adjNode], adjNode});
          }
      }
  }
  return dist;
}

//  *Practice - 1
#include<bits/stdc++.h>
using namespace std;

vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
  priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
  vector<int> dist(V, 0);
          
  for(int i = 0; i < V; i++)
      dist[i] = 1e9;
  
  // * Src will always be reachable at 0 distance
  dist[S] = 0;
  pq.push({0, S});
  
  
  while(!pq.empty()) {

      int nodeDist = pq.top().first;
      int node = pq.top().second;
      
      pq.pop();
      
      for(auto it: adj[node]){
          int edgeWt = it[1]; 
          int adjNode = it[0];

          if(nodeDist + edgeWt < dist[adjNode]){
              dist[adjNode] = nodeDist + edgeWt;
              pq.push({dist[adjNode], adjNode});
          }
      }
  }
  return dist;
}