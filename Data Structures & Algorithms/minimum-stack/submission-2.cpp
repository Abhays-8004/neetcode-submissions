class MinStack {
public:
int minval = INT_MIN;
 multiset<int> minheap;
 stack<int>st;
    MinStack() {
        
    }
    
    void push(int val) {
        minheap.insert(val);
        st.push(val);
    }
    
    void pop() {
        minheap.erase(minheap.find(st.top()));
        st.pop();
        

    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return *minheap.begin();
    }
};
