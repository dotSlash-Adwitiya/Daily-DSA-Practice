#include<bits/stdc++.h>
using namespace std;

int minimumMultiplications(vector<int> &arr, int start, int end) {
  int MOD = 1e5;
  queue<int> q;
  q.push(start);
  int vis[100000] = {0};
  vis[start] = 1;
  
  int cntr = 0;
  while (!q.empty()) {
      cntr++;
      int n = q.size();
      for (int i = 0; i < n; i++) {
          int num = q.front();
          q.pop();
          if (num == end) return cntr - 1;
          
          for (int j = 0; j < arr.size(); j++) {
              int mul = (num * arr[j]) % MOD;
              if (!vis[mul]) {
                  vis[mul] = 1;
                  q.push(mul);
              }
          }
      }
  }
  
  return -1;
}

// * Practice - 1
int minimumMultiplications(vector<int> &arr, int start, int end) {
    int MOD = 1e5;
    queue<int> q;
    q.push(start);
    int vis[100000] = {0};
    vis[start] = 1;
    
    int cntr = 0;
    while (!q.empty()) {
        cntr++;
        int n = q.size();
        for (int i = 0; i < n; i++) {
            int num = q.front();
            q.pop();
            if (num == end) return cntr - 1;
            
            for (int j = 0; j < arr.size(); j++) {
                int mul = (num * arr[j]) % MOD;
                if (!vis[mul]) {
                    vis[mul] = 1;
                    q.push(mul);
                }
            }
        }
    }
    
    return -1;
}