只需在卖出股票时，减去手续费即可。  
```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        // dp[i][0] 表示持有股票能获得的最大利润
        // dp[i][1] 表示不持有股票能获得的最大利润 
        // 假设手续费在卖出股票时计算
        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
        dp[0][0] = -prices[0];
        dp[0][1] = 0; // 第一天要么买入再卖出，要么为 0，买入再卖出还需要交一笔手续费  
        for (int i = 1; i < prices.size(); ++i) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] - prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] + prices[i] - fee);
        }
        return max(dp[prices.size()-1][0], dp[prices.size()-1][1]);
    }
};
```
