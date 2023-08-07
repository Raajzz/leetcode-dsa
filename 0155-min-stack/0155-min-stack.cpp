class MinStack {
public:
    
    // TC - O(1) for all functions
    // SC - O(2*N) because of storing a pair of elements
    
    stack<pair<int,int>> st;
    
    MinStack() {
        int a;
    }
    
    void push(int val) {
        if(st.empty() || st.top().second >= val){
            st.push(make_pair(val, val));    
        } else if(st.top().second < val) {
              st.push(make_pair(val, st.top().second));
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
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