class Solution {
public:
    bool isLetter(char c)
    {
        if((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
            return true;
        else
            return false;
    }
    bool isPalindrome(string s) {
        int begin = 0;
        int end = s.size() - 1;
        while(begin < end)
        {
            while(begin < end && !isLetter(s[begin]))
                ++begin;

            while(begin < end && !isLetter(s[end]))
                --end;   
                
            if(tolower(s[begin]) != tolower(s[end])) 
                return false;
            
            ++begin;
            --end;
        }
        return true;
    }
};