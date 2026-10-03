class MyStack {
public:
    deque<int>dq;

    MyStack() {
        
    }
    
    void push(int x) {
        dq.push_back(x);
    }
    int pop() {
        if(!dq.empty()){
            int t = dq.back();
            dq.pop_back();
            return t;
        }
        
    }
    
    int top() {
        if(!dq.empty()){
            int t = dq.back();
            
            return t;
        }
    }
    
    bool empty() {
       return  dq.empty() == true? true:false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */