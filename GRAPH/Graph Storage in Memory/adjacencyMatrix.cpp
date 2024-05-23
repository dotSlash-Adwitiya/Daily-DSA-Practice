#include<iostream>
#include<vector>
using namespace std;

void createGraphInAdjacencyMatrix(){
   int nodes, edges;
   cout << "Enter no of nodes : ";
   cin >> nodes;
   cout << "Enter no of edges : ";
   cin >> edges;

   // * S.C : O(n²)
   // * +1 is due to 0 based indexing
   int adj[nodes+1][edges+1];

   for (int i = 0; i < edges; i++)
   {
      int node, nodeReverse;
      cin >> node >> nodeReverse;
      adj[node][nodeReverse] = 1;
      adj[nodeReverse][node] = 1;
   }
}

void createWeightedGRAPH(){

}

int main()
{
  
  createGraphInAdjacencyMatrix();
  return 0;
}