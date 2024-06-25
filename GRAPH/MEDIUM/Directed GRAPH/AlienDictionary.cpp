#include<bits/stdc++.h>
using namespace std;

/*
  * If the interviewer asks the following question: 
  * When the order is not possible?
  * Show him following 2 testcases :-
  * Testcase-1 : Cyclic Dependency
  * abcd
  * bat
  * add
  * TestCase-2: Larger string comes before the smaller string:
  * abcd
  * abc
  * Here, it says, a->a, b->b, c->c, d->?
*/

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

string findOrder(string dict[], int N, int K) {
  
  // * Creating Adjacency List of Character type
  vector<int> adj[K];
  
  for(int i = 0; i < N-1; i++) {
      string str1 = dict[i];
      string str2 = dict[i+1];
      
      int len = min(str1.size(), str2.size());
      for(int j = 0; j < len; j++) {
          if(str1[j] != str2[j]){
              adj[str1[j] - 'a'].push_back(str2[j] - 'a');
              break;
          }
      }
  }
  
  vector<int> topo = topoSort(K, adj);
  
  string ans = "";
  for(auto ele: topo)
      ans = ans + char(ele + 'a');
  
  return ans;
}