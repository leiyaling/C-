class Solution {
public:
    string addStrings(string num1, string num2) {
        int end1 = num1.size() - 1;
        int end2 = num2.size() - 1;
        int next = 0;//进位
        string retStr;
        while(end1 >= 0 || end2 >= 0)
        {
            int x1 = 0;
            if(end1 >= 0)
            {
                x1 = num1[end1] - '0';
                --end1;
            }

            int x2 = 0;
            if(end2 >= 0)
            {
                x2 = num2[end2] - '0';
                --end2;
            }
            int retVal = x1 + x2 + next;
            if(retVal > 9)
            {
                next = 1;
                retVal -=10;
            } 
            else
            {
                next = 0;
            }
           retStr += retVal + '0';  
        }
        if(next == 1)
            retStr +='1';
        reverse(retStr.begin(),retStr.end());
        return retStr;
    }
};