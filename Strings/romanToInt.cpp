#include<bits/stdc++.h>
using namespace std;

int convert(char ch) {
    int num = 0;
    switch(ch) {
            case 'I': 
                    num = 1;
                    break;
            case 'V': 
                    num = 5;
                    break;
            case 'X': 
                    num = 10;
                    break;
            case 'L': 
                    num = 50;
                    break;
            case 'C': 
                    num = 100;
                    break;
            case 'D': 
                    num = 500;
                    break;
            case 'M': 
                    num = 1000;
                    break;
        }
        return num;
}
bool isLarger(int num, char ch) {
    int num2 = 0;
    switch(ch) {
            case 'I': 
                    num2 = 1;
                    break;
            case 'V': 
                    num2 = 5;
                    break;
            case 'X': 
                    num2 = 10;
                    break;
            case 'L': 
                    num2 = 50;
                    break;
            case 'C': 
                    num2 = 100;
                    break;
            case 'D': 
                    num2 = 500;
                    break;
            case 'M': 
                    num2 = 1000;
                    break;
        }
        
        return ((num >= num2) ? 1 : 0);
}
int romanToDecimal(string &str) {
    int ans = 0;
    int n = str.size();
    for(int i = 0; i < n-1; i++) {
        char ch = str[i];
        int num = convert(ch);
        if(isLarger(num, str[i+1])){
            ans += num;
        }
        else {
            ans -= num;
        }
    }
    ans += convert(str[n-1]);
    return ans;
}



int main()
{ 
  
  return 0;
}