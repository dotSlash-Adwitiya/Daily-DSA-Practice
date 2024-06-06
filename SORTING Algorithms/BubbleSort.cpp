#include<bits/stdc++.h>
using namespace std;

/*
  * Bubble Sort has following properties
  * 1. It's an Adaptive algorithm, because : If the elements are sorted it takes : O(n) T.C
  * 2. It's a STABLE Algorithm
  * 3. It's an in-place Algorithm
  * 4. T.C : Worst Cast : O(n²), Average Case : O(n²), Best Case : O(n) 
*/

void bubbleSort(int arr[], int n)
{
  //* We have to perform n-1 passes so we take i to n-1 outer loop
  for(int i = 0; i < n-1; i++) {
      //* In each pass, we have to reduce comparisons based on no of elements 
      //* That are already sorted. So, in each pass we sort i-elements. hence n-i-1
      for(int j = 0; j < n-i-1; j++) 
          if(arr[j] > arr[j+1])
              swap(arr[j], arr[j+1]);
  }
}

int main()
{
  int arr [] = {8,5,7,3,2};
  int n = sizeof(arr)/sizeof(arr[0]);

  cout << "Array before performing sorting : " << endl;
  
  for(int i = 0; i < n; i++)
    cout << arr[i] << " ";
  
  cout << endl;

  bubbleSort(arr,n);

  cout << "Array after performing sorting : " << endl;
  for(int i = 0; i < n; i++)
    cout << arr[i] << " ";
  
  return 0;
}