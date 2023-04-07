bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int pushi=0,popi=0;
        while(pushi < pushed.size())
        {
            s.push(pushed[pushi++]);
            while(!s.empty() && s.top() == popped[popi])
            {
                s.pop();
                popi++;
            }
        }
        return popi==popped.size();
    }