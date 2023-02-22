可以这样思考，就成为一个 求装满容量为 n 的背包有多少种方法 + 完全背包问题：  
无限使用 {1,2} 中的元素，给定背包容量为 n，有多少种方法装满？  
且 {1,2},{2,1} 这种算作不同的解，因此是求排列，先遍历背包容量，再遍历元素：  
```cpp
class Solution {
public:
    int climbStairs(int n) {
        // 可以这样思考，就成为一个完全背包问题：
        // 无限使用 {1,2} 中的元素，给定背包容量为 n，有多少种方法装满？
        vector<int> nums = {1,2};
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        int numssize = nums.size();
        for (int j = 0; j <= n; ++j) { // 求排列！外层遍历背包容量，内层遍历元素；比如达到 3，那么 {1,2} 和 {2,1} 都应该算作答案
            for (int i = 0; i < numssize; ++i) {
                if (j >= nums[i])
                    dp[j] = dp[j] + dp[j - nums[i]];
            }
        }
        return dp[n];
    }
};
```
