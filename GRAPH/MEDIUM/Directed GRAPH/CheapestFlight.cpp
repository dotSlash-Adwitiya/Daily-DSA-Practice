#include<bits/stdc++.h>
using namespace std; 



int CheapestFLight(int n, vector<vector<int>> &flights,
                  int src, int dst, int K)
{
  vector<pair<int, int>> adj[n];
  for (auto it : flights)
      adj[it[0]].push_back({it[1], it[2]});
  
  queue<pair<int, pair<int, int>>> q;
  
  q.push({0, {src, 0}});

  vector<int> dist(n, 1e9);
  dist[src] = 0;

  while (!q.empty())
  {
      auto it = q.front();
      q.pop();
      int stops = it.first;
      int node = it.second.first;
      int cost = it.second.second;

      // We stop the process as soon as the limit for the stops reaches.
      if (stops > K)
          continue;
      for (auto iter : adj[node])
      {
          int adjNode = iter.first;
          int edW = iter.second;

          if (cost + edW < dist[adjNode] && stops <= K)
          {
              dist[adjNode] = cost + edW;
              q.push({stops + 1, {adjNode, cost + edW}});
          }
      }
  }
  // If the destination node is unreachable return ‘-1’
  if (dist[dst] == 1e9)
    // else return the calculated dist from src to dst.
      return -1;
  return dist[dst];
}
