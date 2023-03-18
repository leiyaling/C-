int minArray(vector<int>& numbers) {
        int begin = 0;
        int end = numbers.size()-1;
       
        while(begin < end)
        {
             int mid = (begin+end)/2;
            if(numbers[mid] < numbers[end])
                end = mid;
            else if(numbers[mid] > numbers[end])
                begin = mid+1;
            else
                end -= 1;         
        }
        return numbers[begin];
    }