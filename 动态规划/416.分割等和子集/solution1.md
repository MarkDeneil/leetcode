主要的思路点在于：原集合中能否凑出和为 sum/2 的子集合。如果能凑出来，那么问题就解决了。  
那么可以转化为以下思路：背包容量为 sum/2 的背包，能否装满？  
注意，因为背包问题的描述是：背包容量为 j 的背包**能装得下的物品的最大价值**，因此**如果原集合中有和为 sum/2 的子集和，那么背包容量为 sum/2 的背包一定能够装满**。  
```cpp
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // 思路：直接设置背包最大容量为 sum/2，将 nums 中所有元素看作商品，看是否能把背包装满。（即容量为 sum/2 的背包最多可以装多少，如果正好能装满，说明可以找到两个子集的和相同  
        vector<int> dp(10001, 0); // dp[j] 代表背包容量为 j 时最多能容纳的价值为 dp[j]
        dp[0] = 0;
        int sum = 0;
        for (auto x : nums) {
            sum += x;
        }
        if (sum % 2 != 0) return false;
        int target = sum / 2;

        for (int i = 0; i < nums.size(); ++i) {
            for (int j = target; j >= nums[i]; --j) {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        if (dp[target] == target) return true;
        return false;
    }
};
```
