此问题可以转换为：在 nums 中找出和为 left 的组合；则可以描述为 dp 问题：以 nums 数组中的元素，装满容量为 left 的背包有多少种方法？  
设定 dp 数组含义：dp[j] 表示装满容量为 j 的数组有多少种方法（nums 中的每个元素只能用一次，仍然是 01 背包问题）  
直接推导 dp[j] 不好推导，可以使用二维 dp 数组来推导：dp[i][j] 代表使用 nums[0] ~ nums[i] 装满容量为 j 的背包有多少种方法  
则 dp[i][j] ：  
1）若 j < nums[i]，则 dp[i][j] = dp[i-1][j]  
2）若 j >= nums[i] ，则 背包容量为 j 的背包可以装得下 nums[i]  
   - 可以选择装或者不装，如果装的话，有 dp[i-1][j-nums[i]] 种方法把背包装满；如果不装的话，有 dp[i-1][j] 种方法把背包装满  
   - 因此，一共有 dp[i-1][j-nums[i]] + dp[i-1][j] 种方法把容量为 j 的背包装满  
写成一维数组，即 **dp[j] = dp[j-nums[i]] + dp[j]**，且当 j < nums[i] 时，dp[j] 不需要变动，因此只需要考虑 j > nums[i] 的情况即可（这一点和背包理论讲解类似）  
```cpp
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // 本题要如何使表达式结果为target，
        // 既然为target，那么就一定有 left组合 - right组合 = target。
        // left + right = sum，而sum是固定的。right = sum - left
        // 公式来了， left - (sum - left) = target 推导出 left = (target + sum)/2 。
        // target是固定的，sum是固定的，left就可以求出来。
        // 此时问题就是在集合nums中找出和为left的组合。

        int sum = 0;
        for (auto x : nums) {
            sum += x;
        }
        if (sum < target || -sum > target) return 0; // [100],target = -200
        if ((target + sum) % 2) return 0; // 凑不成 target 的情况。如：[1,1,1,1,1] target = 2
        int left = (target + sum) / 2; 

        // 此时我们要找的是：以 nums 数组中的元素，装满容量为 left 的背包有多少种方法
        // dp数组含义：dp[j] 表示装满容量为 j 的数组有多少种方法（每个元素仍然只能用一次，是 01 背包问题）
        // 直接推导 dp[j] 不好推导，可以使用二维 dp 数组来推导：dp[i][j] 代表使用 nums[0] ~ nums[i] 装满容量为 j 的背包有多少种方法
        // 则 dp[i][j] ：
        //  1）若 j < nums[i]，则 dp[i][j] = dp[i-1][j]
        //  2）若 j >= nums[i] ，则 背包容量为 j 的背包可以装得下 nums[i]
        //      可以选择装或者不装，如果装的话，有 dp[i-1][j-nums[i]] 种方法把背包装满；如果不装的话，有 dp[i-1][j] 种方法把背包装满
        //      因此，一共有 dp[i-1][j-nums[i]] + dp[i-1][j] 种方法把容量为 j 的背包装满
        //  写成一位数组，当 dp[j] = dp[j-nums[i]] + dp[j]，且当 j < nums[i] 时，dp[j] 不需要变动，因此只需要考虑 j > nums[i] 的情况即可（这一点和背包理论讲解类似）
        vector<int> dp(left + 1, 0);
        dp[0] = 1; // 这个可以利用 target = 1,nums = [1] 推导一下
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = left; j >= nums[i]; --j) 
                dp[j] += dp[j - nums[i]];
        }

        return dp[left];

        
    }
};
```
