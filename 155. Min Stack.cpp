class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> s;
    stack<int> ss;
    MinStack() 
    {
        int top;
    }
    
    void push(int x) 
    {
        s.push(x);
        if(ss.empty() || x <= ss.top())
        {
            ss.push(x);
        }
        
    }
    
    void pop() {
    
        if(s.top() == ss.top())
            ss.pop();
        
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return ss.top();
    }
};
