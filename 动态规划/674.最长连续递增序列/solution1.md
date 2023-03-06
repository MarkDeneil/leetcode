dp[i] 表示以 nums[i] 结尾的最长严格连续递增子序列长度  
与 300.最长递增子序列 不同，本题 dp[i] 只与 dp[i-1] 有关。  
```cpp
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        // dp[i] 表示以 nums[i] 结尾的最长连续严格递增子序列长度
        vector<int> dp(nums.size(), 1);
        int res = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i-1])
                dp[i] = dp[i-1] + 1; // 显然，与 300.最长递增子序列不同，本题 dp[i] 只与 dp[i-1] 有关
            if (dp[i] > res)
                res = dp[i];
        }
        return res;
    }
};
```
