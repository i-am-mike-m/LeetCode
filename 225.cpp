class MyStack {
public:
    queue<int> enqueue;
    queue<int> to_stack;    
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        enqueue.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        while (enqueue.size() > 1) {
            to_stack.push(enqueue.front());
            enqueue.pop();
        }
        int ret = enqueue.front();        
        enqueue.pop();
        while (!to_stack.empty()) {
            enqueue.push(to_stack.front());
            to_stack.pop();
        }
        return ret;
    }
    
    /** Get the top element. */
    int top() {
       while (enqueue.size() > 1) {
            to_stack.push(enqueue.front());
            enqueue.pop();
        }
        int ret = enqueue.front();
        to_stack.push(enqueue.front());
        enqueue.pop();        
        while (!to_stack.empty()) {
            enqueue.push(to_stack.front());
            to_stack.pop();
        }
        return ret; 
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return enqueue.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */