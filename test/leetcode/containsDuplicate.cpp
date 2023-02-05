bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> um;
        for(auto num : nums)
            ++um[num];
        
        for(auto num : um)
        {
            if(num.second > 1)
                return true;
        }
        return false;
    }