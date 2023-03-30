vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> v(k,0);
        if(k==0)
            return v;
        priority_queue<int> q(arr.begin(),arr.begin()+k);
        for(int i=k;i<arr.size();i++)
        {
            if(arr[i]<=q.top())
            {
                q.pop();
                q.push(arr[i]);
            }
        }
        
        for(int i=0;i<k;i++)
        {
            v[i]=q.top();
            q.pop();
        }
        return v;
    }