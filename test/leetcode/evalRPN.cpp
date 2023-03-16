int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(auto& str : tokens)
        {
            //操作符出栈并计算，计算结果入栈
            if(str == "+" || str == "-" || str == "*" || str == "/")
            {
                int right = s.top();
                s.pop();
                int left = s.top();
                s.pop();

                switch(str[0])//switch必须是整形，char也是整形家族
                {
                    case '+':
                        s.push(left + right);
                        break;
                    case '-':
                        s.push(left - right);
                        break;
                    case '*':
                        s.push(left * right);
                        break;
                    case '/':
                        s.push(left / right);
                        break;
                }
            }
            //操作数入栈
            else
            {
                s.push(stoi(str));
            }

        }
        return s.top();
    }