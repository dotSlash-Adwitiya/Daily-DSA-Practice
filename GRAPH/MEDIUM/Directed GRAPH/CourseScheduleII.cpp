#include<bits/stdc++.h>
using namespace std;

/*
 * The intuition for toposort in this problem comes from the fact that its specicied :
 * Some task is to be PERFORMED BEFORE some other task. 
 */

vector<int> findOrder(int N, int m, vector<vector<int>> prerequisites) 
{
  vector<int> adj[N];
  
  for(auto it: prerequisites) {
      adj[it[1]].push_back(it[0]);
  }
  
  int indegree[N] = {0};
  
    for (int i = 0; i < N; i++) { // * Traversing on Each Vertex
      for (auto it : adj[i]) { // * If an element is found at any node, increase its indegree
        indegree[it]++;
      }
    }
  
    queue<int> q;
    // * Put all the nodes with 0 incoming edge (indegree) in a queue
    for (int i = 0; i < N; i++) {
      if (indegree[i] == 0) {
        q.push(i);
      }
    }
  
    vector<int> topo;
    while (!q.empty()) {
      int node = q.front();
      q.pop();
      topo.push_back(node);
      
      for (auto it : adj[node]) {
        indegree[it]--; // * Decrement the outdegree
        if (indegree[it] == 0) q.push(it);
      }
    }
  
    if(topo.size() == N)
      return topo;
    return {};
}