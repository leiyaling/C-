class Solution {
public:
    int StrToInt(string str) {
        if(str.empty())
            return 0;
        int res = 0;
        int len = str.size();
        int flag = 1;
        int index = 0;
        //处理首位
        if(str[index] == '+')
        {
            flag = 1;
            ++index;
        }   
        else if(str[index] == '-')
        {
            flag = -1;
            ++index;
        }  
        while(index < len)
        {
            if(str[index] < '0' || str[index] > '9')
                return 0;
                
            res = res * 10 + str[index] - '0';
            ++index;
        }
        return flag * res;
    }
};