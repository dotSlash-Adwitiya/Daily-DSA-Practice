#include<bits/stdc++.h>
using namespace std;

string encode(string &msg)
{
    int left = 0;
    int right = 0;
    string ans = "";

    while(left < msg.size() && right < msg.size()) {
        int cnt = 0;

        // * Traverse till we encounter another char or reach the end
        while(right < msg.size() && msg[left] == msg[right]){
            right++;
            cnt++;
        }

        // * Add the occurence count and the character to the ans string
        ans += msg[left];
        ans += to_string(cnt);

        // * Bring the left ptr to the right
        if(right < msg.size())
            left = right;
    }
    return ans;
}