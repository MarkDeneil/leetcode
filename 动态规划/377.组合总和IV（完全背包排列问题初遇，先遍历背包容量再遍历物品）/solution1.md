本题可以使用回溯算法，超时。  
nums 中的元素可以使用无限次，完全背包问题。 
本题也是求**装满容量为 target 的背包有多少种方法**，因此是完全背包问题 和 有多少种方法凑满容量为j的背包（494.目标和）的结合。  
本题中，(1,1,2) 和 (2,1,1) 是不同的答案，因此是**求排列数问题**，完全背包先遍历背包容量，再遍历物品。  
```cpp
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        // dp[i] : 装满目标值 i 的元素组合的个数
        // 如果求组合数就是外层for循环遍历物品，内层for遍历背包。(组合数:{1,5})
        // 如果求排列数就是外层for遍历背包，内层for循环遍历物品。(排列数:{1,5},{5,1})
        vector<unsigned long long> dp(target + 1, 0);
        dp[0] = 1;
        for (int j = 0; j <= target; ++j) { // 求排列数，需要先遍历背包容量，再遍历物品
            for (int i = 0; i < nums.size(); ++i) {
                if (j >= nums[i]) 
                    dp[j] = dp[j] + dp[j-nums[i]]; // 求
            }
        }
        return dp[target];
    }
};
```
