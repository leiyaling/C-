vector<string> uncommonFromSentences(string s1, string s2) {
        string s = s1 + ' ' + s2;
        vector<string> v;
        for(int i=0;i<s.size();i++)
        {
            string tmp;
            while(i<s.size() && s[i] != ' ')
            {
                tmp += s[i];
                ++i;
            }
            v.push_back(tmp);
        }

        unordered_map<string,int> um;
        for(auto s : v)
            ++um[s];
        v.clear();    
        for(auto s : um)
        {
            if(s.second == 1)
            {
                v.push_back(s.first);
            }
        }
        return v;
    }