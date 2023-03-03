本题可以根据 123.买卖股票的最佳时机III 的两笔交易推导为多笔交易  
如果题目中说明了完成 k 笔交易，再设置 dp[i][0]，并按照交易的笔数设置 dp[i][1],dp[i][2], ...   
```cpp
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2*k + 1, 0));
        // 本题可以根据 123.买卖股票的最佳时机III 的两笔交易推导为多笔交易
        // 如果题目中说明了完成 k 笔交易，再设置 dp[i][0]，并按照交易的笔数设置 dp[i][1],dp[i][2], ... 
        // dp[i][0] 表示一直未操作
        // dp[i][1] 表示第一次持有股票获得的最大利润（指第一次买入以及第一次买入之后一直未卖出)
        // dp[i][2]: 第一次不持有股票（指第一次买入一只股票后又卖出）
        // dp[i][3]：第二次持有股票
        // dp[i][4]：第二次不持有股票
        // dp[i][2*k-1]：第 k 次持有股票
        // dp[i][2*k]：第 k 次不持有股票
        dp[0][0] = 0;
        for (int i = 1; i <= k; ++i) {
            dp[0][2*i - 1] = -prices[0];
            dp[0][2*i] = 0;
        }
        for (int i = 1; i < prices.size(); ++i) {
            for (int j = 1; j <= k; ++j) {
                dp[i][2*j-1] = max(dp[i-1][2*j-1], dp[i-1][2*j-1-1] - prices[i]); // 这里，第 i 天的第 j 次持有股票（dp[i-1][2*j-1]）要将第 j-1 次不持有股票的利润加上，以实现多笔交易的最大利润
                dp[i][2*j] = max(dp[i-1][2*j], dp[i-1][2*j-1] + prices[i]);
            }
        }
        int res = 0;
        for (auto x : dp[prices.size()-1]) 
            if (x > res) 
                res = x;
        return res;
    }
};
```
