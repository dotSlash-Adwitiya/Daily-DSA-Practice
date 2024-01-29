#include<bits/stdc++.h>
using namespace std;

/* 
 *
 * Leetcode constraints defined , ele pushed will be - 1 <= ele <= 9
 * Peek and pop are always a valid operation
*/ 


 // * Recursive Approach, using SINGLE stack
class MyRecursiveQueue {
public:
    stack<int> stk;
    int firstEle;

    MyRecursiveQueue() {
    }
    
    void push(int x) {
        stk.push(x);

        //* If this is the first ele, store it for PEEK operation
        if(stk.size() == 1)
            firstEle = x;
    }

    // * Recursive Function
    void removeEle(stack<int> &stk, int & topEle){
        if(stk.size() == 1){
            topEle = stk.top();
            stk.pop();
            return;
        }
        
        // * Extract & save ele for later pushing while returning
        int ele = stk.top();
        stk.pop();
        
        removeEle(stk, topEle);

        // * Push all ele while returning
        stk.push(ele);

        //* If after deleting, this is the first ele, store it for PEEK operation
        if(stk.size() == 1)
            firstEle = ele;
    }
    
    int pop() {
        if(stk.size() == 0)
            return -1;

        //* Transfer all elements to temp stack
        int topEle = 0;
        removeEle(stk, topEle);
        return topEle;
    }
    
    int peek() {
        if(stk.size() == 0)
            return -1;
        return firstEle;
    }
    
    bool empty() {
        return (stk.size() == 0);
    }
};
/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */


class MyQueue {
public:
    stack<int> stk1;
    stack<int> stk2;
    
    MyQueue() {
    }
    
    void push(int x) {
        stk1.push(x);
    }
    
    int pop() {
        if(stk1.size() == 0) 
            return -1;

        //* Transfer all elements to temp stack
        while(stk1.size() != 1) {
            stk2.push(stk1.top());
            stk1.pop();
        }
        int val = stk1.top();
        stk1.pop();
        
        // * Reassign elements to the 1st stack
        while(!stk2.empty()) {
            stk1.push(stk2.top());
            stk2.pop();
        }

        return val;
    }
    
    int peek() {
        if(stk1.size() == 0)
            return -1;
        //* Transfer all elements to temp stack
        while(stk1.size() != 1) {
            stk2.push(stk1.top());
            stk1.pop();
        }
        int val = stk1.top();
        
        while(!stk2.empty()) {
            stk1.push(stk2.top());
            stk2.pop();
        }
        return val;
    }
    
    bool empty() {
        return(stk1.size() == 0);
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */