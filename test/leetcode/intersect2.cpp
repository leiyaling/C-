vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m;
        for(auto e : nums1)
        {
           ++m[e];
        }
        vector<int> v;
        for(auto e : nums2)
        {
            if(m.count(e))
            {
                v.push_back(e);
                --m[e];
                if(m[e] == 0)
                 m.erase(e);
            } 
            
        }
        return v;
    }