本题的主要思路在于：想清楚 dp\[i] 代表什么：dp\[i] 代表爬到第 i 个阶梯时最少需要多少代价  
因为可以选择从第 0 阶或者第 1 阶开始爬，因此爬到第 0 阶或者第 1 阶所需的最小代价就是 0，即 dp\[0] = 0;dp\[1] = 0;  
公式：dp\[i] = min(dp\[i-1] + cost\[i-1], dp\[i-2] + cost\[i-2]);
```cpp
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int step = cost.size();
        // dp 数组代表到达第 i 层需要的最小费用
        vector<int> dp(step+1);
        if (step < 2) return min(cost[0], cost[1]);
        dp[0] = 0;
        dp[1] = 0;
        for (int i = 2;i <= step; ++i) {
            dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
        }
        return dp[step];
    }
};
```
