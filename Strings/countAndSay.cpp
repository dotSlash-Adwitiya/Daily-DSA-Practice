
#include<bits/stdc++.h>
using namespace std;

string lookandsay(int n) {
    if(n==1) return "1";
    if(n==2) return "11";
    
    string str = "11";
    string temp = "";
    for(int i = 3; i < n; i++) {
        int cnt = 0, j = 0;
        int l = str.length();
        char ch = str[0];
        while(j < l) {
            
            while(j < l && ch == str[j]) cnt++;
            
            str += to_string(cnt) + ch;                       
            j = cnt;
        }    
        }
    
    return str;
}

int main()
{
  int arr[] = {1,2,3,4,5};

  vector<int> v = {10,20,30,40,50};

  cout << lookandsay(4) << endl;

  return 0;
}