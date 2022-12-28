class Solution {
public:
    string reverseStr(string s, int k) {
        int end = s.size();//闭区间
        for(int i = 0;i < end; i += 2*k)
        {
            reverse(s.begin() + i,s.begin() + min(i+k,end));
        }
      return s;      
    }
};