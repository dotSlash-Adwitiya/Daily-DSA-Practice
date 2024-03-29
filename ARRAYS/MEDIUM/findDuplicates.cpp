#include <iostream>
#include <vector>
using namespace std;

vector<int> duplicates(int arr[], int n)
{
    // First check all the values that are present in an array.
    // Then go to that values as indexes and increment by the size of array.
    for (int i = 0; i < n; i++)
    {
        int index = arr[i] % n;
        arr[index] += n;
    }        

    // Now check which value exists more than once by dividing with the size of array
    bool flag = false;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if ((arr[i] / n) > 1)
        {
            ans.push_back(i);
            flag = true;
        }
    }
    if (!flag)
    {
        ans.push_back(-1);
    }
    return ans;
}