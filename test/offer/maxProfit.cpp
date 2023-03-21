int maxProfit(vector<int>& prices) {
        //用一个变量记录一个历史最低价格 minprice，我们就可以假设自己的股票是在那天买的。那么我们在第 i 天卖出股票能得到的利润就是 prices[i] - minprice。
        //只需要遍历价格数组一遍，记录历史最低点，然后在每一天考虑这么一个问题：如果我是在历史最低点买进的，那么我今天卖出能赚多少钱？当考虑完所有天数之时，我们就得到了最好的答案。
        if(prices.empty())
            return 0;
        int minp=prices[0];
        int cost=0;
        for(int i=1;i<prices.size();i++)
        {
            minp=min(prices[i],minp);
            cost=max(prices[i]-minp,cost);
        }
        return cost;
    }