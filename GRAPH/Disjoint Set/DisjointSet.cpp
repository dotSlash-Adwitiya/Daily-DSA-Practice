#include<bits/stdc++.h>
using namespace std;

class DisjointSet {
  vector<int> parent, rank, size;
  public:
  DisjointSet(int n) {
    // parent.resize(n, 0); // * For 0 based graphs (N-1 Nodes)
    // rank.resize(n, 0); // * For 0 based graphs (N-1 Nodes)
    parent.resize(n+1, 0); // * for 1 based graphs (N Nodes) But this works for both 0 and 1 based
    rank.resize(n+1, 0); // * for 1 based graphs (N Nodes) But this works for both 0 and 1 based
    size.resize(n+1, 1); // * for 1 based graphs (N Nodes) But this works for both 0 and 1 based

    for(int i = 0; i <= n; i++){
      parent[i] = i;
    }
  }

  
  int findParent(int node){
    if(node == parent[node]) 
      return node;
      // * 'parent[node]=' allows PATH COMPRESSION 
    return parent[node] = findParent(parent[node]); 
  }

  /* 
    * Note: Both Union By Size and UnionByRank have T.C: O(4α) Has a very huge mathematical derivation. 
    * Hence not asked in interviews.
  */
  void unionByRank(int u, int v){
    int ulp_u = findParent(u);
    int ulp_v = findParent(v);

    if(ulp_u == ulp_v) return;

    if(rank[ulp_u] < rank[ulp_v]){
      parent[ulp_u] = ulp_v;
    }
    else if(rank[ulp_v] < rank[ulp_u]){
      parent[ulp_v] = ulp_u;
    }
    else{ // * Either way works, just make sure to increase the rank of the node which is being attached to.
      parent[ulp_v] = ulp_u;
      rank[ulp_u]++;
    }
  }

  void unionBySize(int u, int v){
    int ulp_u = findParent(u);
    int ulp_v = findParent(v);

    if(ulp_u == ulp_v) return;

    if(size[ulp_u] < size[ulp_v]){
      parent[ulp_u] = ulp_v;
      size[ulp_v] += size[ulp_u];
    } else {
      parent[ulp_v] = ulp_u;
      size[ulp_u] += size[ulp_v];

    }

  }
};

int main()
{
  int n = 7;
  DisjointSet ds(n);
  // ds.unionByRank(1, 2);
  // ds.unionByRank(2, 3);
  // ds.unionByRank(4, 5);
  // ds.unionByRank(6, 7);
  // ds.unionByRank(5, 6);
  // * If 3 and 7 both belong to the same component 
  // * or not before creating hypothetical edge b/w 3 and 7

  ds.unionBySize(1, 2);
  ds.unionBySize(2, 3);
  ds.unionBySize(4, 5);
  ds.unionBySize(6, 7);
  ds.unionBySize(5, 6);

  if(ds.findParent(3) == ds.findParent(7))
    cout << "SAME!" << endl;
  else 
    cout << "NOT SAME!" << endl;
  
  ds.unionBySize(3, 7);

  if(ds.findParent(3) == ds.findParent(7))
    cout << "SAME!" << endl;
  else 
    cout << "NOT SAME!" << endl;
  // cout << ds.findParent(0) << endl; // * 0
  // cout << ds.findParent(1) << endl; // * 0

  return 0;
}