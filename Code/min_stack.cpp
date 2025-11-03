// https://leetcode.com/problems/min-stack/description/
// Difficulty: Medium
// Tags: Stacks

class MinStack {
    stack<long long> st;
    long long mini;
public:
    MinStack() {
        st.empty();
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            mini=val;
        }
        else{
            if(val<mini){
                st.push(2ll*val - mini);
                mini=val;
            }
            else{
                st.push(val);
            }
        }
    }
    
    void pop() {
        if(mini>st.top()){
            mini = 2*mini - st.top();
        }
        st.pop();
    }
    
    int top() {
        return max(st.top(), mini);
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */