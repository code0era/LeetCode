// Last updated: 2/11/2026, 12:54:48 AM
class MinStack {
    stack<long long> s , m ;  
public:
    MinStack() {}
    
    void push(int val) {
        s.push(val);

        if(m.empty()|| val<=m.top()) m.push(val);
    }
    
    void pop() {
        if(s.top() == m.top()) m.pop();
        s.pop();
        
    }
    
    int top() {
       return s.top();
    }
    
    int getMin() {
        return m.top();
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