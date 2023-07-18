#include <bits/stdc++.h>
using namespace std;

//* Function to check if the brackets pair match
bool check(char a, char b) {
    if(a == '(' && b == ')')
        return true;
    if(a == '{' && b == '}')
        return true;
    if(a == '[' && b == ']')
        return true;
    return false;
}

//* Approach 1 : TC & SC : O(N)
//* Function to check if brackets are balanced or not.
bool ispar(string x)
{
    stack<char> stk;
    int n = x.length();
    
    for(int i = 0; i < n; i++) {
        if(x[i] == '(' || x[i] == '{' || x[i] == '[' )
            stk.push(x[i]);
        
        else {
            if(!stk.empty()) {
                char ch = stk.top();
                if(!check(ch, x[i])) return false;
                stk.pop();
            }   
            else return false;
        }
    }
    if(!stk.empty())
        return false;
    return true;
}

//* Approach 2 : (More optimized) TC: O(N), SC: O(1)
//* In this approach, we make use of a left pointer. ->> Derived from removed duplicates questions.
//Function to check if brackets are balanced or not.
bool ispar(string x)
{
    stack<char> stk;
    int n = x.length(), left = -1;
    
    for(int i = 0; i < n; i++) {
        if(x[i] == '(' || x[i] == '{' || x[i] == '[')
            x[++left] = x[i];
        else {
            if(left >= 0 && check(x[left], x[i]))
                left--;
            else return false;
        }
    }
    if(left == -1)
        return true;
    return false;
}


int main() {

int arr[] = {1,2,3,4,5};

vector<int> v;

return 0;
}