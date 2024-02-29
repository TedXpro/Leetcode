class MyCircularQueue {
private:
    vector<int> queue;
    int front;
    int rear;
    int size;
    int currentElements;
public:
    MyCircularQueue(int k) {
        queue.resize(k);
        front = -1;
        rear = -1;
        size = k;
        currentElements = 0;
    }
    
    bool enQueue(int value) {
        if(isFull())
            return false;
        rear = (rear + 1) % size;
        queue[rear] = value;
        currentElements++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty())
            return false;
        front = (front + 1) % size;
        currentElements--;
        return true;
    }
    
    int Front() {
        if(isEmpty())
            return -1;
        return queue[(front + 1) % size];
    }
    
    int Rear() {
        if(isEmpty())
            return -1;
        return queue[rear];
    }
    
    bool isEmpty() {
        return currentElements == 0;
    }
    
    bool isFull() {
        return currentElements == size;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */