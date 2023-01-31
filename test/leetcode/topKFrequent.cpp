 vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> countMap;
        for(auto& str : words)
        {
            countMap[str]++;
        }

        multimap<int,string,greater<int>> sortMap;

        for(auto& kv : countMap)
        {
            sortMap.insert(make_pair(kv.second,kv.first));
        }
        vector<string> v;
        auto it = sortMap.begin();
        while(k--)
        {
            v.push_back(it->second);
            ++it;
        }
        return v;
    }