当前元素大于 连续子数组和加上元素本身 并且最大值比元素还小时， 抛弃前面的连续子数组，重新开始计算连续数组和
加上当前元素后，数组和比最大值还大，则连续该元素  

class Solution {
public:
     int FindGreatestSumOfSubArray(vector<int> array) 
    {
        int cursum=array[0];
        int maxsum=array[0];
        for(int i=1;i<array.size();i++)
        {
            cursum += array[i];
            if(cursum < array[i])
                cursum = array[i];
            if(cursum > maxsum)
                maxsum = cursum;       
        }
        return maxsum;

  }
};