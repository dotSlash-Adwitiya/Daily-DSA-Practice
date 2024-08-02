#include<bits/stdc++.h>
using namespace std;

int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
  queue<pair<string,int>> q;
  q.push({startWord,1});
  
  unordered_set<string> st(wordList.begin(), wordList.end());
  st.erase(startWord);
  
  while(!q.empty()){
      string word = q.front().first;
      int transformation = q.front().second;
      string original = word;
      
      q.pop();
      
      if(word == targetWord)
      return transformation;
      
      for(int i = 0; i < word.size(); i++) {
          char original = word[i];
          for(char ch = 'a'; ch <= 'z'; ch++) {
              word[i] = ch;
              if(st.find(word) != st.end()){
                  st.erase(word);
                  q.push({word, transformation+1});
              }
          }
          word[i] = original;
      }    
  }
  return 0;
}

// * Practice - 1
int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
    queue<pair<string,int>> q;
    q.push({startWord,1});
    
    unordered_set<string> st(wordList.begin(), wordList.end());
    st.erase(startWord);
    
    while(!q.empty()){
        string word = q.front().first;
        int transformation = q.front().second;
        string original = word;
        
        q.pop();
        
        if(word == targetWord)
        return transformation;
        
        for(int i = 0; i < word.size(); i++) {
            char original = word[i];
            for(char ch = 'a'; ch <= 'z'; ch++) {
                word[i] = ch;
                if(st.find(word) != st.end()){
                    st.erase(word);
                    q.push({word, transformation+1});
                }
            }
            word[i] = original;
        }    
    }
    return 0;
}