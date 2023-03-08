子序列问题 dp[i] 定义两种思路总结：  
1. dp[i] 表示以 nums[i] 结尾的...(这种情况下，nums[i] 肯定要加入到 dp[i] 中，可以以此为起点推导 dp 数组)  
2. dp[i] 表示 到 numss[i] 位置满足题目条件的数组...  
本题中用 dp[i] 表示以 nums[i] 结尾的最大和的连续子数组的和（尝试一个以“dp[i] 为 到 nums[i] 为止的最大连续子数组的和”定义，发现并不好实现）  
```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // 子序列问题 dp[i] 定义两种思路总结：
        // 1. dp[i] 表示以 nums[i] 结尾的...(这种情况下，nums[i] 肯定要加入到 dp[i] 中，可以以此为起点推导 dp 数组)
        // 2. dp[i] 表示 到 numss[i] 位置满足题目条件的数组...
        // dp[i] 表示以 nums[i] 结尾的最大和的连续子数组的和（尝试一个以“dp[i] 为 到 nums[i] 为止的最大连续子数组的和”定义，发现并不好实现）
        vector<int> dp(nums.size(), 0);

        dp[0] = nums[0];
        int res = dp[0];
            
        for (int i = 1; i < nums.size(); ++i) {
            if (dp[i-1] >= 0) // 推导思路：nums[0] 肯定是要加到 dp[i] 中的，那么下面就考虑 dp[i-1] 需不需要加入到 dp[i] 中，那么自然就要判断 dp[i-1] 与 0 的大小，如果大于 0 就加到 dp[i] 中
                dp[i] = dp[i-1] + nums[i];
            else 
                dp[i] = nums[i];
            res = max(res, dp[i]);
        }

    return res;
    }
};
```
