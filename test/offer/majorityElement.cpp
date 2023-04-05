int majorityElement(vector<int>& nums) {
        int result=nums[0];
        int times=1;
        for(int i=1;i<nums.size();i++)
        {
            if(times != 0)
            {
                if(result==nums[i])
                {
                    times++;
                }
                else
                {
                    times--;
                }
            }
            else
            {
                result = nums[i];
                times = 1;
            }
        }
        times=0;
        for(int num :nums)
        {
            if(num==result)
                times++;
        }
        return times>(nums.size()/2)?result:0;
    }