class MyQueue {
private:
     stack<int> pushq;
     stack<int> popq;
public:
    MyQueue() {
       
    }
    
    void push(int x) {
        pushq.push(x);
    }
    
    int pop() {
        if(popq.empty())
        {
             while(!pushq.empty())
            {
                popq.push(pushq.top());
                pushq.pop();
            }
        }
        int x=popq.top();
        popq.pop();
        return x;
    }
    
    int peek() {
        if(popq.empty())
        {
             while(!pushq.empty())
            {
                popq.push(pushq.top());
                pushq.pop();
            }
        }
        return popq.top();
    }
    
    bool empty() {
        return pushq.empty() && popq.empty();
    }
};