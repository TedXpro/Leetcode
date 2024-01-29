class MyQueue {
    stack<int> queueStack, tempStack;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!queueStack.empty()){
            tempStack.push(queueStack.top());
            queueStack.pop();
        }
        queueStack.push(x);

        while(!tempStack.empty()){
            queueStack.push(tempStack.top());
            tempStack.pop();
        }
    }
    
    int pop() {
        int num = queueStack.top();
        queueStack.pop();
        return num;
    }
    
    int peek() {
        return queueStack.top();
    }
    
    bool empty() {
        return queueStack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */