注意，打家劫舍系列没有容量限制，已经不属于背包问题了  
围绕成一圈，因为首尾不能同时偷，所以可以考虑以下两方面：  
![20210129160821374](https://user-images.githubusercontent.com/83362131/222154888-e27aafd3-642c-40a8-b50b-ec798ba36052.jpg)  
![20210129160842491](https://user-images.githubusercontent.com/83362131/222154921-67d487e8-3e6e-4f1c-9ef9-3b9e4b00d54d.jpg)  

```cpp
int robb(vector<int> & nums) {
    vector<int> newnums(nums.size() + 1, 0);
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

class Solution {
public:
    int rob(vector<int>& nums) {
        // 没有“容量”限制，已经不是背包问题了
        // 要么一定不偷首元素，要么一定不偷尾元素，因此分成两个情况
        // 有一个问题：当不考虑首元素时，会不会出现“正好没选尾元素，而且首元素后面的元素也没有选”的情况？这种情况加上首元素不是一个更好的选择吗？
        // 这种情况实际上在 不考虑尾元素时 已经考虑过了。在不考虑尾元素时，如果遇到了首元素没选，首元素后面的元素也没选时，dp 数组一定会从中选一个
        if (nums.size() == 1) 
            return nums[0];
        vector<int> nums1(nums.begin(), nums.end() - 1);
        vector<int> nums2(nums.begin() + 1, nums.end());
        int res = max(robb(nums1), robb(nums2));
        return res;
    }
};
```
