#include<bits/stdc++.h>
using namespace std;

vector<int> nearestPerfectSquare(int N) {
    
    vector<int> ans;
    
    int root = round(pow(N,0.5));
    int sqr = pow(root,2);
    int diff = abs(N-sqr);
    
    ans.push_back(sqr);
    ans.push_back(diff);
    return ans;
}

int main()
{
  int arr[] = {1,2,3,4,5};

  vector<int> v = {10,20,30,40,50};


  return 0;
}