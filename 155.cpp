class MinStack {
    private: 
     stack<pair<int,int>> st;
public:
    MinStack() {
    //    
    }
    
    void push(int x) {
        int mini;
        if(st.empty()) mini = x;
        else{
            mini = min(st.top().second,x);
        }
        st.push({x,mini});
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

