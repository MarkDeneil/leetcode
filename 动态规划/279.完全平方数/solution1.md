仍然是二维 dp 数组解法和一维 dp 数组解法：  
```cpp
class Solution {
public:
    int numSquares(int n) {
        // 将 10000 以内的所有完全平方数作为元素，则可以看作完全背包问题。
        // 求返回和为 n 的完全平方数的最少数量，所以不需要关注是组合或排列，可以直接先遍历元素，再遍历背包容量
        vector<int> nums;
        for (int i = 1; i <= 100; ++i) 
            nums.push_back(pow(i, 2));
        int size = nums.size();
        // dp[i][j] 表示使用 nums[0] ~ nums[i]，和为 j 的完全平方数的最少数量为 dp[i][j]
        vector<vector<unsigned int>> dp(size, vector<unsigned int>(n + 1, INT_MAX));
        for (int i = 0; i < size; ++i) 
            dp[i][0] = 0;
        for (int j = 0; j <= n; ++j) 
            dp[0][j] = j; // 只使用 nums[0](即 1)
        for (int i = 1; i < size; ++i) 
            for (int j = 1; j <= n; ++j) {
                if (j < nums[i]) // j 放不下 nums[i] 
                    dp[i][j] = dp[i-1][j];
                else {
                    dp[i][j] = min(dp[i][j - nums[i]] + 1, dp[i-1][j]); // 放得下，但选择放或者不放
                }
            }
        return dp[size-1][n];
    }
};
```
```cpp
class Solution {
public:
    int numSquares(int n) {
        // 将 10000 以内的所有完全平方数作为元素，则可以看作完全背包问题。
        // 求返回和为 n 的完全平方数的最少数量，所以不需要关注是组合或排列，可以直接先遍历元素，再遍历背包容量
        vector<int> nums;
        for (int i = 1; i <= 100; ++i) 
            nums.push_back(pow(i, 2));

        // dp[i] 表示和为 i 的完全平方数的最少数量
        vector<unsigned int> dp(n + 1, INT_MAX);
        dp[0] = 0; // 如果只初始化 dp[1] = 1，不通过，因为后面求 min 的计算中会使用 dp[0]，比如 i = 1（此时 dp[i] 等于 4），j = 4 时，dp[j - nums[i]] 应该为 dp[0] 应该为 0
        for (int i = 0; i < nums.size(); ++i) 
            for (int j = nums[i]; j <= n; ++j) {
                    dp[j] = min(dp[j], dp[j - nums[i]] + 1); // 从 dp[j] 往前推一小步，假如容量为 j 的背包中已经有了一个 nums[i]，则所需的最少数量是 1 + dp[j - nums[i]]，加 1 表示加上 nums[i] 这个数
            }
        return dp[n];
        
    }
};
```
