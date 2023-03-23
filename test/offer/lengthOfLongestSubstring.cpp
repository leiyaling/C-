int lengthOfLongestSubstring(string s) {
        unordered_set<char> occ;
        int n=s.size();
        int k=0;int ret=0;
        for(int i=0;i<n;i++)
        {
            while(k<n && !occ.count(s[k]))
            {
                occ.insert(s[k]);
                ++k;
            }
            ret=max(ret,k-i);
            occ.erase(s[i]);
        }
        return ret;
    }