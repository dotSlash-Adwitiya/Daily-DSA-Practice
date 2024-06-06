
/*
  * The basic Idea in this is to ASSUME, that element at 0th index is ALREADY SORTED, 
  * so we start with 1st index(2nd element)
  * Then we start shifting elements directly
  * And shift until we find a correct position
*/

/*
  * Properties of Insertion Sort :
  * 1. Its a STABLE Algorithm : (In case of duplicate elements, it doesn't change the order after sorting)
  * 2. Its ADAPTIVE in Nature : (If elements are already SORTED, then it takes LESS time - O(n))
  * 3. Its an IN-PLACE Algorithm
*/

#include<bits/stdc++.h>
using namespace std;

  void insert(int arr[], int i)
    {
        int ele = arr[i];
        int j = i;
        while(j > 0 && ele < arr[j-1]){
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = ele;
    }

    void insertionSort(int arr[], int n)
    {
        for(int i = 1; i < n; i++) 
            insert(arr, i);
        
    }


int main()
{
  int arr [] = {8,5,7,3,2};
  int n = sizeof(arr)/sizeof(arr[0]);

  cout << "Array before performing sorting : " << endl;
  
  for(int i = 0; i < n; i++)
    cout << arr[i] << " ";
  
  cout << endl; 


  cout << "Array after performing sorting : " << endl;
  for(int i = 0; i < n; i++)
    cout << arr[i] << " ";
  
  return 0;
}