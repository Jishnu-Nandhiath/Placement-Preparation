class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int profit = 0,b=INT_MAX;
        for(int i = 0; i< prices.size(); i++)
        {
            if(prices[i] < b)
            {
                b = prices[i];
            }
            else if(profit < (prices[i] - b))
            {
                profit = prices[i] - b;
            }
                }
    return profit;        
    }
};
