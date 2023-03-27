vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size();i++)
        {
            int m=nums[i];
            int n=i+1;
            int k=nums.size()-1;
            while(n<k)
            {
                if(m+nums[n]+nums[k] == 0)
                {
                    ret.push_back({m,nums[n],nums[k]});
                    ++n;
                    --k;
                    while(n<k && nums[n]==nums[n-1])
                        ++n;
                    while(n<k && nums[k]==nums[k+1])
                        --k;
                }
                else if(m+nums[n]+nums[k] < 0)
                {
                    ++n;
                }
                else
                {
                    --k;
                }
            }
            while(i+1<nums.size() && nums[i+1]==nums[i])
                ++i;
        }
        return ret;
    }