class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int ret = 0;
        for(auto e : nums)
        {
            ret ^= e;
        }
        int rets = (ret == INT_MIN ? ret : ret & (-ret));//防止溢出
        
        int sum1 = 0;
        int sum2 = 0;
        for (int num: nums) {
            if (num & rets) {
                sum1 ^= num;
            }
            else {
                sum2 ^= num;
            }
        }
        return {sum1,sum2};
    }
};