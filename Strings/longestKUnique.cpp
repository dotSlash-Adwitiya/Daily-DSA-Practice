#include<bits/stdc++.h>
using namespace std;

int longestKSubstr(string s, int k) {
    
    int maxi = -1, left = 0;
    unordered_map<char, int> unq;
    
    for(int right = 0; right < s.size(); right++) {

        //* Include in unq_map
        unq[s[right]]++;
        
        //* Check if the size of unordered_map exceed k
        //* So, till the size exceeds k, inc left *ptr and start dec freq of char at left *ptr;
        //* Remove from unq_map till the freq again becomes <= k.
        while(unq.size() > k) {
            unq[s[left]]--;
            //* If the element's freq becomes 0, REMOVE IT!
            if(unq[s[left]] == 0) unq.erase(s[left]);    
            left++;
        }        

        //* Store the max size of the SubString
        if(unq.size() == k) maxi = max(maxi, right-left+1);
    }    
    return maxi;
}