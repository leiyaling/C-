//栈的压入、弹出序列
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int> _st;
        int pushi=0,popi=0;
        while(pushi < pushV.size())
        {
            _st.push(pushV[pushi]);
            ++pushi;
            while(!_st.empty() && _st.top() == popV[popi])
            {
                _st.pop();
                ++popi;
            }
            
        }
       return popi == pushV.size(); 
    }
};