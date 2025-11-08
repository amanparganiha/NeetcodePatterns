#include <bits/stdc++.h>
class MinStack {
private:
   stack<int> st;
   stack<int> minSt;

public:
    MinStack() { }
    
    void push(int val) {
        st.push(val);
        val = min(val , minSt.empty() ? val : minSt.top());
        minSt.push(val);
    }
    
    void pop() {
        if(!st.empty() && !minSt.empty()){
        st.pop();
        minSt.pop();
        }
    }
    
    int top() {
       if(!st.empty()) return st.top();
       throw runtime_error("Stack is empty!");
    }
    
    int getMin() {
       if(!minSt.empty()) return minSt.top();
       throw runtime_error("Stack is empty!");
    }
};

