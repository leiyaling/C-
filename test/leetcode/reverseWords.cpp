class Solution {
public:
    string reverseWords(string s) {
        int end = s.size();
        int i = 0;
        while(i < end)
        {
            //找单词
            int begin = i;
            while(i < end && s[i] != ' ')
                ++i;
            
            int left =begin; 
            int right = i-1;
            //反转
            while(left < right)
            {
                swap(s[left],s[right]);
                ++left;
                --right;
            }
            //跳过空格
            while(i < end && s[i] == ' ')
                ++i;
        }
        return s;
    }
};