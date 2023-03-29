bool isStraight(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int joker=0;//大小王数量
        for(int i=0;i<4;i++)
        {
            if(nums[i] == 0) 
                joker++; // 统计大小王数量
            else if(nums[i] == nums[i + 1]) 
                return false; // 若有重复，提前返回 false
        }
        return nums[4]-nums[joker] < 5;//最大牌减最小牌的值小于5可构成顺子
    }