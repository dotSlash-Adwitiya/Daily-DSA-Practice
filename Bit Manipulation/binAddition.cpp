#include<bits/stdc++.h>
using namespace std;

string addBinary(string A, string B)
{
    int i = A.size()-1, j = B.size()-1;

	    string ans = "";
	    
	    int carry = 0;
	    while(i >= 0 && j >= 0) {
	        int t1 = A[i] - '0';
	        int t2 = B[j] - '0';
	        
	        if(t1 + t2 + carry == 2) {
	         ans.insert(0, "0");
	         carry = 1;
	        }
	        
	        else if(t1 + t2 + carry == 3) {
	         ans.insert(0, "1");
	         carry = 1;
	        }
	        
	        else if(t1 + t2 + carry == 1) {
	         ans.insert(0, "1");
           carry = 0;
	        }
	        
	        else {
	         ans.insert(0, "0");
           carry = 0;
	        }
          i--;
          j--;
	    }
	    
	    while(i >= 0) {
        if(A[i] == '1' && carry == 0)
          ans.insert(0, "1");
        else 
          ans.insert(0, "0");
        i--;
      }
	        
	    while(j >= 0) {
        if(B[j] == '1' && carry == 0)
          ans.insert(0, "1");
        else 
          ans.insert(0, "0");
        j--;
      }

	    if(carry)
        ans.insert(0, "1");
      
	    return ans;
}

int main()
{ 
  cout << "Hello" << endl;
  // cout << addBinary("100", "1101") << endl;

  long long n = 2;
  cout << n % 2 << endl;

  return 0;
}