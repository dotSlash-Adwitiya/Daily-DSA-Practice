#include<bits/stdc++.h>
using namespace std;

void printPat(int n)
{
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = n; j >=1; j--) {
            for(int k = 1; k <= n-cnt; k++){
                cout << j << " ";
            }
        }
        cnt++;
        cout << "$";
    }
}