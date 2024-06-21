#include<bits/stdc++.h>
using namespace std;

bool isPossible(int N,int P, vector<pair<int, int> >& prerequisites) {
  vector<int> adj[N];
  for(auto ele: prerequisites)
      adj[ele.first].push_back(ele.second);
      
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

  int cnt = 0;
  while (!q.empty()) {
    int node = q.front();
    q.pop();
    cnt++;
    
    for (auto it : adj[node]) {
      indegree[it]--; // * Decrement the outdegree
      if (indegree[it] == 0) q.push(it);
    }
  }

  if(cnt == N)
    return true;
  return false;
}