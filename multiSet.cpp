#include<bits/stdc++.h>
using namespace std;

void fun() {
  multiset<int> st;

  st.insert(1);
  st.insert(2);
  st.insert(3);
  st.insert(3);
  st.insert(4);
  st.insert(5);
  st.insert(1);

  for(auto it : st)
    cout << it << endl;

    cout << endl;

  // Erase all instances and returns the total number of occurences removed
  cout << "Total occurences removed : " << st.erase(1) << endl;

  // Erase only one occurrence (or instance)
  st.erase(st.find(3));

  for(auto it : st)
    cout << it << endl;

}

int main()
{
  fun();

  return 0;
}