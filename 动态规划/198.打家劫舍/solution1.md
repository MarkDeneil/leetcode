dp\[i]:偷 1~i 家房间所能获得的最大收益  
```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
        // dp[i]:偷 1~i 家房间所能获得的最大收益
        if (nums.size() == 1) 
            return nums[0];
        vector<int> dp(101, 0);
        dp[0] = 0;
        dp[1] = nums[0];
        for (int i = 2; i <= nums.size(); ++i) {
            // 偷第 i 家房间，那么肯定不偷第 i-1 家，因此 dp[i] = dp[i-2] + nums[i]
            // 不偷第 i 家房间，那么 dp[i] 就是偷 0~i-1 家房间所能获得的最大收益（注意，此时不一定偷第 i-1 家）,dp[i] = dp[i-1]
            // 取两者之大
            dp[i] = max(dp[i-2] + nums[i-1], dp[i-1]); // nums[i-1] 代表第 i 家房子的现金
        }
        return dp[nums.size()];
    }
};
```
