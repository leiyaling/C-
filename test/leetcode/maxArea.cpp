int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;

        int result = 0;
        while(left < right)
        {
            int area = min(height[left],height[right]) * (right - left);//容器能装多少水，取决于矮的那一边
            result = max(result,area);

            if(height[left] < height[right])
            {
                ++left;
            }
            else
            {
                --right;
            }
        }

        return result;
    }