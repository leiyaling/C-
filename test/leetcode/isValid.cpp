bool isValid(string s) {
        stack<char> st;
        for(auto e : s)//左括号入栈，右括号出栈顶元素进行匹配
        {
            if(e=='[' || e=='{' || e=='(')
            {
                st.push(e);
            }
            else
            {
                if(st.empty())//栈里没有右括号可以匹配
                {
                    return false;
                }
                int top = st.top();
                st.pop();
                if((e == '}' && top != '{')
                || (e == ']' && top != '[')
                || (e == ')' && top != '('))
                {
                    return false;
                }
            }
        }
        bool ret = st.empty();//栈为空，代表括号全部匹配完
        return ret;
    }