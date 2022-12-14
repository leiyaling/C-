class MinStack {
public:
    MinStack() {

    }
    
    void push(int val) {
        _st.push(val);
        //栈里面没有数据 或者出现小于等于栈顶元素的数 就入栈（最小数据）
        if(_minST.empty() || _minST.top() >= val)
            _minST.push(val);
    }
    
    void pop() {
        if(_minST.top() == _st.top())
            _minST.pop();
        _st.pop();
    }
    
    int top() {
        return _st.top();
    }
    
    int getMin() {
        return _minST.top();
    }
private:
    stack<int> _st;
    stack<int> _minST;

};