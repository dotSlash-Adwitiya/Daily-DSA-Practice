#include<bits/stdc++.h>
using namespace std;

// * Optimised space in ADJACENCY LIST!!
// * Every node in the ADJACENCY LIST consists of the LIST of thes nodes that are ADJACENT (NEIGHBOUR Nodes) to it  
// * S.C : O(2E), E = Edges Because every edge is connected with 2 nodes
// * Undirected GRAPH
void createAdjacencyListUndirectedGraph() {
  int nodes, edges;
  cin >> nodes;
  vector<vector<int>> adj(nodes+1);

  // * Undirected GRAPH
  for(int i = 0; i < edges; i++) {
    int node, nodeReverse; // * u and v
    cin >> node, nodeReverse;
    /* 
       * Ex1 : node = 1, nodeReverse = 4. So, 1--4 and 4--1.
       * Ex2 : node = 4, nodeReverse = 7. So, 4--7 and 7--4.
       * Now, 4--1 and 4--7
    */
    adj[node].push_back(nodeReverse);
    adj[nodeReverse].push_back(node);
  }
}

// * S.C : O(E) (Because edges are directed)
void createAdjacencyListDirectedGraph() {
  int nodes, edges;
  cin >> nodes;
  vector<vector<int>> adj(nodes+1);

  // * Directed GRAPH
  for(int i = 0; i < edges; i++) {
    int node, nodeReverse; // * U and V
    cin >> node, nodeReverse;
    adj[node].push_back(nodeReverse);
    // adj[nodeReverse].push_back(node); // * This will be omitted because, of the DIRECTIONS SPECIFIED
  }
}

// * S.C : O(E)
// * For Matrix : adjMatrix[u][v] = weight
// * For List: Store PAIR<ConnectedEgde,WEIGHT>
void createAdjacencyListWeightedGraph() {

}