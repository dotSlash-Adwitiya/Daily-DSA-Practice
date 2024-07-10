#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string str, int start, int end){
    while(start < end) {
        if(str[start++] != str[end--])
            return false;
    }
    return true;
}

void f(string str, int idx, vector<string> &path, vector<vector<string>> & ans) {
    if(idx == str.size()){
        ans.push_back(path);
        return;
    }

    for(int i = idx; i < str.size(); i++) {
        if(isPalindrome(str, idx, i)){
            // * Extract the substring from initial idx till current (ith) index.
            string temp = str.substr(idx, i - idx + 1);
            path.push_back(temp);
            f(str, i+1, path, ans);
            path.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    vector<string> list;
    f(s, 0, list, ans);
    return ans;
}