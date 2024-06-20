#include <bits/stdc++.h>
using namespace std;

vector<int> topoSort(int V, vector<int> adj[])
{
  int indegree[V] = {0};

  // * Count and STORE the indegree of every node
  for (int i = 0; i < V; i++) { // * Traversing on Each Vertex
    for (auto it : adj[i]) { // * If an element is found at any node, increase its indegree
      indegree[it]++;
    }
  }

  queue<int> q;
  // * Put all the nodes with 0 incoming edge (indegree) in a queue
  for (int i = 0; i < V; i++) {
    if (indegree[i] == 0) {
      q.push(i);
    }
  }

  vector<int> topo;

  while (!q.empty()) {
    int node = q.front();
    q.pop();
    topo.push_back(node);

    // * node is in your topo sort
    // * so please remove it from the indegree

    for (auto it : adj[node]) {
      indegree[it]--; // * Decrement the outdegree
      if (indegree[it] == 0) q.push(it);
    }
  }

  return topo;
}
