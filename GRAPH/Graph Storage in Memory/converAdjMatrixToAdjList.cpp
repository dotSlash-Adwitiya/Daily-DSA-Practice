#include<bits/stdc++.h>
using namespace std;


void convert(vector<vector<int>> &adjMatrix, int V, vector<int> adjList[]){

  for (int i = 0; i < V; i++)
  {
    for (int j = 0; j < V; j++)
    {
      if(adjMatrix[i][j] == 1 && i != j)
        adjList[i].push_back(j);
        adjList[j].push_back(i);
    }
  }
}