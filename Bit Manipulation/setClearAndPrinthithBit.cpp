#include<bits/stdc++.h>
using namespace std;

void bitManipulation(int n, int i) {
    
    //* Create a bit_mask
    int bit_mask = (1 << i-1);

    //* Check if the ith bit is on,
    //* if its on set_bit = 1 else 0
    int ith_bit = ((n & bit_mask) == 0 ? 0 : 1);
    
    cout << ith_bit << " ";
    
    //* if the ith bit isn't already set, then set it.
    if(ith_bit == 0)
        cout << (n | bit_mask) << " ";
    
    //* If ith-bit is already set then simply print it.
    else 
        cout << n << " ";
    
    // if the ith_bit isn't already clear then clear it using XOR.
    if(ith_bit != 0) 
        cout << (n ^ bit_mask) << " ";

    else 
        cout << n << " ";
}

int main()
{
  int n, i;
  cout << "Enter the number & ith_bit to check, set and clear the ith bit : " << endl;
  cin >> n >> i;

  bitManipulation(n, i);

  return 0;
}