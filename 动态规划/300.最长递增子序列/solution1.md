dp[i] 表示 i 之前（包括 i）的以 nums[i] 结尾的最长递增子序列的长度  
思考之后发现，**dp[i] 不仅仅与 dp[i-1] 有关；应该遍历所有的 dp[0] ~ dp[i-1]，如果 nums[i] 大于 nums[0] ~ nums[i-1]中的一个，那么就有可能更新 dp[i]**  
```cpp

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // dp[i]表示i之前包括i的以nums[i]结尾的最长递增子序列的长度
        vector<int> dp(nums.size(), 1); // 都初始化为 1，因为只要 nums[i] 本身可以做子序列
        dp[0] = 1;
        int res = 1;
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) { // 做本题的时候思考，dp[i] 是之和 dp[i-1] 有关，还是和 dp[0]...dp[i-1] 都有关系？如果都有关系，那么直接用循环遍历
                if (nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            if (dp[i] > res) res = dp[i];
        }
        return res; // 这里不是返回 dp[nums.size()-1]，注意 dp[i] 的定义，最长子序列不一定以 nums[nums.size()-1] 结尾
    }
};
```
