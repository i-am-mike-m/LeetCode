class MyQueue {
public:
    stack<int> buildUp;
    stack<int> popOut;
    
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        buildUp.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int top;
        if (popOut.empty()) {
            while (!buildUp.empty()) {
                popOut.push(buildUp.top());
                buildUp.pop();
            }
        }
        top = popOut.top();
        popOut.pop();
        
        return top;
    }
    
    /** Get the front element. */
    int peek() {
        if (popOut.empty()) {
            while (!buildUp.empty()) {
                popOut.push(buildUp.top());
                buildUp.pop();
            }
        }
        return popOut.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return buildUp.empty() && popOut.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */