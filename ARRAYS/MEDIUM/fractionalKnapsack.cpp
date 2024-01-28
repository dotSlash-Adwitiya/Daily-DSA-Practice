#include<bits/stdc++.h>
using namespace std;

struct Item {
  int value;
  int weight;
};

//* It is important to have this as static
static bool comparator(const Item& a, const Item& b) {
    double ratioA = (double)(a.value) / a.weight;
    double ratioB = (double)(b.value) / b.weight;
    return ratioA > ratioB; // Sort in descending order, adjust as needed
}

double fractionalKnapsack(int W, Item arr[], int n) {
    sort(arr, arr + n, comparator);
    double ans = 0;

    for (int i = 0; i < n; i++) {
        
        // * Extract the min weight
        int minWt = min(W, arr[i].weight);
        
        // * Get the profits
        ans += (double) ((arr[i].value * minWt) )/ (arr[i].weight);
        W -= minWt;
    }
  return ans;
}