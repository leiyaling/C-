int missingNumber(vector<int>& nums) {
        int n = nums.size()+1;
        for(int i=0;i<nums.size();i++)
        {
            if(i!=nums[i])
            {
                return i;
            }
            
        }
        return n-1;
    }