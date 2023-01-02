class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if(numbers.empty())
            return 0;
        sort(numbers.begin(),numbers.end());
        int mid = (numbers.size())/2;
        int count = 0;
        for(auto num : numbers)
        {
            if(num == numbers[mid])
                count++;
        }
        if(count > mid)
            return numbers[mid];
        else
            return 0;
    }
};