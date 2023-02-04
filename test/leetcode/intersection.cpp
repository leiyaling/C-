vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1;
        for(auto e : nums1)
        {
            s1.insert(e);
        }
        set<int> s2;
        for(auto e : nums2)
        {
            s2.insert(e);
        }
        auto it1 = s1.begin();
        auto it2 = s2.begin();
        vector<int> v;
        while(it1 != s1.end() && it2 != s2.end())
        {
            if(*it1 < *it2)
            {
                it1++;
            }
            else if(*it2 < *it1)
            {
                it2++;
            }
            else
            {
                v.push_back(*it1);
                it1++;
                it2++;
            }
        }
        
        return v;
    }